const util              = require('util')
    , AbstractLevelDOWN = require('abstract-leveldown').AbstractLevelDOWN

    , binding           = require('bindings')('leveldown.node').leveldown

    , ChainedBatch      = require('./chained-batch')
    , Iterator          = require('./iterator')


function LevelDOWNHyper (location) {
  if (!(this instanceof LevelDOWNHyper))
    return new LevelDOWNHyper(location)

  AbstractLevelDOWN.call(this, location)
  this.binding = binding(location)
}

util.inherits(LevelDOWNHyper, AbstractLevelDOWN)


LevelDOWNHyper.prototype._open = function (options, callback) {
  this.binding.open(options, callback)
}


LevelDOWNHyper.prototype._close = function (callback) {
  this.binding.close(callback)
}


LevelDOWNHyper.prototype._put = function (key, value, options, callback) {
  this.binding.put(key, value, options, callback)
}


LevelDOWNHyper.prototype._get = function (key, options, callback) {
  this.binding.get(key, options, callback)
}


LevelDOWNHyper.prototype._del = function (key, options, callback) {
  this.binding.del(key, options, callback)
}


LevelDOWNHyper.prototype._chainedBatch = function () {
  return new ChainedBatch(this)
}


LevelDOWNHyper.prototype._batch = function (operations, options, callback) {
  return this.binding.batch(operations, options, callback)
}


LevelDOWNHyper.prototype._approximateSize = function (start, end, callback) {
  this.binding.approximateSize(start, end, callback)
}


LevelDOWNHyper.prototype.getProperty = function (property) {
  if (typeof property != 'string')
    throw new Error('getProperty() requires a valid `property` argument')

  return this.binding.getProperty(property)
}


LevelDOWNHyper.prototype._iterator = function (options) {
  return new Iterator(this, options)
}


LevelDOWNHyper.destroy = function (location, callback) {
  if (arguments.length < 2)
    throw new Error('destroy() requires `location` and `callback` arguments')

  if (typeof location != 'string')
    throw new Error('destroy() requires a location string argument')

  if (typeof callback != 'function')
    throw new Error('destroy() requires a callback function argument')

  binding.destroy(location, callback)
}


LevelDOWNHyper.repair = function (location, callback) {
  if (arguments.length < 2)
    throw new Error('repair() requires `location` and `callback` arguments')

  if (typeof location != 'string')
    throw new Error('repair() requires a location string argument')

  if (typeof callback != 'function')
    throw new Error('repair() requires a callback function argument')

  binding.repair(location, callback)
}


module.exports = LevelDOWNHyper
