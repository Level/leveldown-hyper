/* Copyright (c) 2012-2017 LevelDOWN contributors
 * See list at <https://github.com/level/leveldown#contributing>
 * MIT License <https://github.com/level/leveldown/blob/master/LICENSE.md>
 */

#include <node.h>
#include <node_buffer.h>

#include <hyperleveldb/write_batch.h>
#include <hyperleveldb/filter_policy.h>

#include "database.h"
#include "leveldown.h"
#include "async.h"
#include "database_async.h"

namespace leveldown {

/** OPEN WORKER **/

OpenWorker::OpenWorker (
    Database *database
  , Nan::Callback *callback
  , leveldb::Cache* blockCache
  , const leveldb::FilterPolicy* filterPolicy
  , bool createIfMissing
  , bool errorIfExists
  , bool compression
  , uint32_t writeBufferSize
  , uint32_t blockSize
  , uint32_t maxOpenFiles
  , uint32_t blockRestartInterval
) : AsyncWorker(database, callback, "leveldown-hyper:db.open")
{
  options = new leveldb::Options();
  options->block_cache            = blockCache;
  options->filter_policy          = filterPolicy;
  options->create_if_missing      = createIfMissing;
  options->error_if_exists        = errorIfExists;
  options->compression            = compression
      ? leveldb::kSnappyCompression
      : leveldb::kNoCompression;
  options->write_buffer_size      = writeBufferSize;
  options->block_size             = blockSize;
  options->max_open_files         = maxOpenFiles;
  options->block_restart_interval = blockRestartInterval;
};

OpenWorker::~OpenWorker () {
  delete options;
}

void OpenWorker::Execute () {
  SetStatus(database->OpenDatabase(options));
}

/** CLOSE WORKER **/

CloseWorker::CloseWorker (
    Database *database
  , Nan::Callback *callback
) : AsyncWorker(database, callback, "leveldown-hyper:db.close")
{};

CloseWorker::~CloseWorker () {}

void CloseWorker::Execute () {
  database->CloseDatabase();
}

void CloseWorker::WorkComplete () {
  Nan::HandleScope scope;
  HandleOKCallback();
  delete callback;
  callback = NULL;
}

/** IO WORKER (abstract) **/

IOWorker::IOWorker (
    Database *database
  , Nan::Callback *callback
  , const char *resource_name
  , leveldb::Slice key
  , v8::Local<v8::Object> &keyHandle
) : AsyncWorker(database, callback, resource_name)
  , key(key)
{
  Nan::HandleScope scope;

  SaveToPersistent("key", keyHandle);
};

IOWorker::~IOWorker () {}

void IOWorker::WorkComplete () {
  Nan::HandleScope scope;

  DisposeStringOrBufferFromSlice(GetFromPersistent("key"), key);
  AsyncWorker::WorkComplete();
}

/** READ WORKER **/

ReadWorker::ReadWorker (
    Database *database
  , Nan::Callback *callback
  , leveldb::Slice key
  , bool asBuffer
  , bool fillCache
  , v8::Local<v8::Object> &keyHandle
) : IOWorker(database, callback, "leveldown-hyper:db.get", key, keyHandle)
  , asBuffer(asBuffer)
{
  Nan::HandleScope scope;

  options = new leveldb::ReadOptions();
  options->fill_cache = fillCache;
  SaveToPersistent("key", keyHandle);
};

ReadWorker::~ReadWorker () {
  delete options;
}

void ReadWorker::Execute () {
  SetStatus(database->GetFromDatabase(options, key, value));
}

void ReadWorker::HandleOKCallback () {
  Nan::HandleScope scope;

  v8::Local<v8::Value> returnValue;
  if (asBuffer) {
    //TODO: could use NewBuffer if we carefully manage the lifecycle of `value`
    //and avoid an an extra allocation. We'd have to clean up properly when not OK
    //and let the new Buffer manage the data when OK
    returnValue = Nan::CopyBuffer((char*)value.data(), value.size()).ToLocalChecked();
  } else {
    returnValue = Nan::New<v8::String>((char*)value.data(), value.size()).ToLocalChecked();
  }
  v8::Local<v8::Value> argv[] = {
      Nan::Null()
    , returnValue
  };
  callback->Call(2, argv, async_resource);
}

/** DELETE WORKER **/

DeleteWorker::DeleteWorker (
    Database *database
  , Nan::Callback *callback
  , leveldb::Slice key
  , bool sync
  , v8::Local<v8::Object> &keyHandle
  , const char *resource_name
) : IOWorker(database, callback, resource_name, key, keyHandle)
{
  Nan::HandleScope scope;

  options = new leveldb::WriteOptions();
  options->sync = sync;
  SaveToPersistent("key", keyHandle);
};

DeleteWorker::~DeleteWorker () {
  delete options;
}

void DeleteWorker::Execute () {
  SetStatus(database->DeleteFromDatabase(options, key));
}

/** WRITE WORKER **/

WriteWorker::WriteWorker (
    Database *database
  , Nan::Callback *callback
  , leveldb::Slice key
  , leveldb::Slice value
  , bool sync
  , v8::Local<v8::Object> &keyHandle
  , v8::Local<v8::Object> &valueHandle
) : DeleteWorker(database, callback, key, sync, keyHandle, "leveldown-hyper:db.put")
  , value(value)
{
  Nan::HandleScope scope;

  SaveToPersistent("value", valueHandle);
};

WriteWorker::~WriteWorker () { }

void WriteWorker::Execute () {
  SetStatus(database->PutToDatabase(options, key, value));
}

void WriteWorker::WorkComplete () {
  Nan::HandleScope scope;

  DisposeStringOrBufferFromSlice(GetFromPersistent("value"), value);
  IOWorker::WorkComplete();
}

/** BATCH WORKER **/

BatchWorker::BatchWorker (
    Database *database
  , Nan::Callback *callback
  , leveldb::WriteBatch* batch
  , bool sync
) : AsyncWorker(database, callback, "leveldown-hyper:db.batch")
  , batch(batch)
{
  options = new leveldb::WriteOptions();
  options->sync = sync;
};

BatchWorker::~BatchWorker () {
  delete batch;
  delete options;
}

void BatchWorker::Execute () {
  SetStatus(database->WriteBatchToDatabase(options, batch));
}

/** APPROXIMATE SIZE WORKER **/

ApproximateSizeWorker::ApproximateSizeWorker (
    Database *database
  , Nan::Callback *callback
  , leveldb::Slice start
  , leveldb::Slice end
  , v8::Local<v8::Object> &startHandle
  , v8::Local<v8::Object> &endHandle
) : AsyncWorker(database, callback, "leveldown-hyper:db.approximateSize")
  , range(start, end)
{
  Nan::HandleScope scope;

  SaveToPersistent("start", startHandle);
  SaveToPersistent("end", endHandle);
};

ApproximateSizeWorker::~ApproximateSizeWorker () {}

void ApproximateSizeWorker::Execute () {
  size = database->ApproximateSizeFromDatabase(&range);
}

void ApproximateSizeWorker::WorkComplete() {
  Nan::HandleScope scope;

  DisposeStringOrBufferFromSlice(GetFromPersistent("start"), range.start);
  DisposeStringOrBufferFromSlice(GetFromPersistent("end"), range.limit);
  AsyncWorker::WorkComplete();
}

void ApproximateSizeWorker::HandleOKCallback () {
  Nan::HandleScope scope;

  v8::Local<v8::Value> returnValue = Nan::New<v8::Number>((double) size);
  v8::Local<v8::Value> argv[] = {
      Nan::Null()
    , returnValue
  };
  callback->Call(2, argv, async_resource);
}

LiveBackupWorker::LiveBackupWorker (
    Database *database
  , Nan::Callback *callback
  , leveldb::Slice name
  , v8::Local<v8::Object> &nameHandle
) : AsyncWorker(database, callback, "leveldown-hyper:db.liveBackup")
  , name(name)
{
  Nan::HandleScope scope;

  SaveToPersistent("name", nameHandle);
};

LiveBackupWorker::~LiveBackupWorker () {}

void LiveBackupWorker::Execute () {
  SetStatus(database->LiveBackup(name));
}

void LiveBackupWorker::WorkComplete () {
  Nan::HandleScope scope;

  DisposeStringOrBufferFromSlice(GetFromPersistent("name"), name);
  AsyncWorker::WorkComplete();
}

} // namespace leveldown
