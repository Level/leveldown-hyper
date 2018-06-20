const test = require('tape')
const testCommon = require('abstract-leveldown/testCommon')
const leveldown  = require('../')
const abstract   = require('abstract-leveldown/abstract/iterator-range-test')

abstract.all(leveldown, test, testCommon)
