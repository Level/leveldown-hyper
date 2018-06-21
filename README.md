# leveldown-hyper

[![level badge][level-badge]](https://github.com/level/awesome)
[![npm](https://img.shields.io/npm/v/leveldown-hyper.svg)](https://www.npmjs.com/package/leveldown-hyper)
[![Build Status](https://img.shields.io/travis/Level/leveldown-hyper.svg)](http://travis-ci.org/Level/leveldown-hyper)
[![dependencies](https://david-dm.org/Level/leveldown-hyper.svg)](https://david-dm.org/level/leveldown-hyper)
[![npm](https://img.shields.io/npm/dm/leveldown-hyper.svg)](https://www.npmjs.com/package/leveldown-hyper)
[![JavaScript Style Guide](https://img.shields.io/badge/code_style-standard-brightgreen.svg)](https://standardjs.com)

`leveldown-hyper` is a fork of `leveldown` and uses [`HyperLevelDB`](https://github.com/rescrv/HyperLevelDB) as backend. It extends the `leveldown` api with functionality to do live backups. This README only documents the `liveBackup()` method. For a complete reference we refer to [`leveldown`](https://github.com/Level/leveldown).

`leveldown` can be considered an upstream repository to `leveldown-hyper` and any common logic and bug fixes will be merged from upstream into this repository.

**If you are upgrading:** please see [UPGRADING.md](UPGRADING.md).

### `db.liveBackup(name, callback)`
<code>liveBackup()</code> is an instance method on an existing database object, used to make a live backup of the current state of the database.

The `name` parameter is a `String`. A successful live backup will result in a backup folder named `backup-:name` inside the `location` folder of the current database.

The `callback` function will be called with no arguments when a live backup was successful, or with a single `error` argument if the backup operation failed for any reason.

## Community

`leveldown-hyper` is an **OPEN Open Source Project**. This means that:

> Individuals making significant and valuable contributions are given commit-access to the project to contribute as they see fit. This project is more like an open wiki than a standard guarded open source project.

See the [contribution guide](https://github.com/Level/community/blob/master/CONTRIBUTING.md) for more details.

## License

[MIT](./LICENSE.md) © 2012-present [Contributors](./CONTRIBUTORS.md).

`leveldown-hyper` is licensed under the MIT license. All rights not explicitly granted in the MIT license are reserved. See the included `LICENSE.md` file for more details.

*`leveldown-hyper` builds on the excellent work of the [`HyperLevelDB`](https://github.com/rescrv/HyperLevelDB) team and the LevelDB and Snappy teams from Google and additional contributors. HyperLevelDB, LevelDB and Snappy are issued under the [New BSD Licence](http://opensource.org/licenses/BSD-3-Clause).*

[level-badge]: http://leveldb.org/img/badge.svg
