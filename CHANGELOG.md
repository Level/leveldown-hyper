# Changelog

## [2.0.0] - 2018-06-21

### Changed

- Update README style ([**@ralphtheninja**](https://github.com/ralphtheninja))
- Rewrite CHANGELOG ([**@ralphtheninja**](https://github.com/ralphtheninja))
- Upgrade `abstract-leveldown` from `~2.6.2` to `~5.0.0` ([**@ralphtheninja**](https://github.com/ralphtheninja))
- Upgrade `prebuild` devDependency from `^6.2.1` to `^7.0.0` ([**@ralphtheninja**](https://github.com/ralphtheninja))
- Upgrade `tape` devDependency from `~4.8.0` to `~4.9.0` ([**@ralphtheninja**](https://github.com/ralphtheninja))
- Add `iota-array` to devDependencies ([**@ralphtheninja**](https://github.com/ralphtheninja))
- Add `lexicographic-integer` to devDependencies ([**@ralphtheninja**](https://github.com/ralphtheninja))
- Enable multiple seeks with buffers ([level/leveldown#323](https://github.com/Level/leveldown/issues/323)) ([**@peakji**](https://github.com/peakji), [**@ralphtheninja**](https://github.com/ralphtheninja))
- Implement iterator fast seek ([level/leveldown#329](https://github.com/Level/leveldown/issues/329)) ([**@peakji**](https://github.com/peakji), [**@ralphtheninja**](https://github.com/ralphtheninja))

### Added

- Add node 9 and 10 to Travis ([**@ralphtheninja**](https://github.com/ralphtheninja))
- Add `standard` ([**@ralphtheninja**](https://github.com/ralphtheninja))
- Add `UPGRADING.md` ([**@ralphtheninja**](https://github.com/ralphtheninja))
- Add `remark` tooling ([**@ralphtheninja**](https://github.com/ralphtheninja))

### Removed

- Remove node 0.12, 4, 5 and 7 from Travis ([**@ralphtheninja**](https://github.com/ralphtheninja))
- Remove g++-4.8 addon from Travis ([**@ralphtheninja**](https://github.com/ralphtheninja))

### Fixed

- Make native code run on node 10 ([level/leveldown#452](https://github.com/Level/leveldown/issues/452)) ([**@ralphtheninja**](https://github.com/ralphtheninja))
- Implement iterator memory leak fix from leveldown ([level/leveldown#264](https://github.com/Level/leveldown/issues/264)) ([**@chjj**](https://github.com/chjj), [**@ralphtheninja**](https://github.com/ralphtheninja))
- Release iterator snapshots ([level/leveldown#267](https://github.com/Level/leveldown/issues/267)) ([**@chjj**](https://github.com/chjj), [**@ralphtheninja**](https://github.com/ralphtheninja))
- Closing db with open iterator should not crash ([level/leveldown#368](https://github.com/Level/leveldown/issues/368)) ([**@peakji**](https://github.com/peakji), [**@ralphtheninja**](https://github.com/ralphtheninja))

## [1.1.3] - 2017-08-15

### Changed

- Upgrade `abstract-leveldown` from `~2.2.1` to `~2.6.2` ([**@greenkeeper**](https://github.com/greenkeeper))
- Upgrade `bindings` from `~1.2.1` to `~1.3.0` ([**@greenkeeper**](https://github.com/greenkeeper))
- Upgrade `prebuild` from `^4.1.1` to `^6.2.1` ([**@greenkeeper**](https://github.com/greenkeeper))
- Upgrade `mkfiletree` devDependency from `~0.0.1` to `~1.0.1` ([**@greenkeeper**](https://github.com/greenkeeper))
- Upgrade `rimraf` devDependency from `~2.2.8` to `~2.6.1` ([**@greenkeeper**](https://github.com/greenkeeper))
- Upgrade `tape` devDependency from `~4.0.0` to `~4.8.0` ([**@greenkeeper**](https://github.com/greenkeeper))
- Update copyright in README ([**@ralphtheninja**](https://github.com/ralphtheninja))
- Move `prebuild` to devDependencies ([**@ralphtheninja**](https://github.com/ralphtheninja))

### Added

- Add node 6, 7 and 8 to Travis ([**@ralphtheninja**](https://github.com/ralphtheninja))
- Add osx to Travis ([**@ralphtheninja**](https://github.com/ralphtheninja))
- Add `prebuild-install` ([**@ralphtheninja**](https://github.com/ralphtheninja))
- Add `prebuild-ci` ([**@ralphtheninja**](https://github.com/ralphtheninja))

### Removed

- Remove node 0.10 from Travis ([**@ralphtheninja**](https://github.com/ralphtheninja))
- Remove global CXX env from Travis ([**@ralphtheninja**](https://github.com/ralphtheninja))

## [1.1.2] - 2017-05-05

### Changed

- Upgrade `nan` from `~2.2.1` to `^2.6.2` ([**@kessler**](https://github.com/kessler))

## [1.1.1] - 2016-04-19

### Changed

- Upgrade `nan` from `~2.0.0` to `~2.2.1` ([**@hxoht**](https://github.com/hxoht))
- Upgrade `prebuild` from `^2.5.0` to `^4.1.1` ([**@ralphtheninja**](https://github.com/ralphtheninja))

### Added

- Add node 5 to Travis ([**@mafintosh**](https://github.com/mafintosh))

## [1.1.0] - 2015-09-23

### Changed

- Upgrade `nan` from `~1.8.4` to `~2.0.0` ([**@ralphtheninja**](https://github.com/ralphtheninja))
- Update c++ code with `nan` changes from `leveldown` ([**@ralphtheninja**](https://github.com/ralphtheninja))
- Patch iterator functionality with `iterator.seek()` ([**@ralphtheninja**](https://github.com/ralphtheninja))
- Update `.liveBackup()` to work with latest `nan` ([**@ralphtheninja**](https://github.com/ralphtheninja))

### Added

- Add `prebuild` ([**@ralphtheninja**](https://github.com/ralphtheninja))

## 1.0.0 - 2015-05-19

**Historical Note** This release was not the first, but marks the version where `leveldown-hyper` was extracted from the `leveldown` repository.

[2.0.0]: https://github.com/Level/leveldown-hyper/compare/v1.1.3...v2.0.0

[1.1.3]: https://github.com/Level/leveldown-hyper/compare/v1.1.2...v1.1.3

[1.1.2]: https://github.com/Level/leveldown-hyper/compare/v1.1.1...v1.1.2

[1.1.1]: https://github.com/Level/leveldown-hyper/compare/v1.1.0...v1.1.1

[1.1.0]: https://github.com/Level/leveldown-hyper/compare/v1.0.0...v1.1.0
