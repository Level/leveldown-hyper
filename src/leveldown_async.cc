/* Copyright (c) 2012-2015 LevelDOWN contributors
 * See list at <https://github.com/level/leveldown#contributing>
 * MIT License <https://github.com/level/leveldown/blob/master/LICENSE.md>
 */

#include <hyperleveldb/db.h>

#include "leveldown.h"
#include "leveldown_async.h"

namespace leveldown {

/** DESTROY WORKER **/

DestroyWorker::DestroyWorker (
    NanUtf8String* location
  , NanCallback *callback
) : AsyncWorker(NULL, callback)
  , location(location)
{};

DestroyWorker::~DestroyWorker () {
  delete location;
}

void DestroyWorker::Execute () {
  leveldb::Options options;
  SetStatus(leveldb::DestroyDB(**location, options));
}

/** REPAIR WORKER **/

RepairWorker::RepairWorker (
    NanUtf8String* location
  , NanCallback *callback
) : AsyncWorker(NULL, callback)
  , location(location)
{};

RepairWorker::~RepairWorker () {
  delete location;
}

void RepairWorker::Execute () {
  leveldb::Options options;
  SetStatus(leveldb::RepairDB(**location, options));
}

} // namespace leveldown
