# leveldown-hyper

[![level badge][level-badge]](https://github.com/Level/awesome)
[![npm](https://img.shields.io/npm/v/leveldown-hyper.svg?label=&logo=npm)](https://www.npmjs.com/package/leveldown-hyper)
[![Node version](https://img.shields.io/node/v/leveldown-hyper.svg)](https://www.npmjs.com/package/leveldown-hyper)
[![Travis](https://img.shields.io/travis/Level/leveldown-hyper.svg?logo=travis&label=)](https://travis-ci.org/Level/leveldown-hyper)
[![npm](https://img.shields.io/npm/dm/leveldown-hyper.svg?label=dl)](https://www.npmjs.com/package/leveldown-hyper)
[![Coverage Status](https://coveralls.io/repos/github/Level/leveldown-hyper/badge.svg)](https://coveralls.io/github/Level/leveldown-hyper)
[![JavaScript Style Guide](https://img.shields.io/badge/code_style-standard-brightgreen.svg)](https://standardjs.com)
[![Backers on Open Collective](https://opencollective.com/level/backers/badge.svg?color=orange)](#backers)
[![Sponsors on Open Collective](https://opencollective.com/level/sponsors/badge.svg?color=orange)](#sponsors)

`leveldown-hyper` is a fork of `leveldown` and uses [`HyperLevelDB`](https://github.com/rescrv/HyperLevelDB) as backend. It extends the `leveldown` api with functionality to do live backups. This README only documents the `liveBackup()` method. For a complete reference we refer to [`leveldown`](https://github.com/Level/leveldown).

`leveldown` can be considered an upstream repository to `leveldown-hyper` and any common logic and bug fixes will be merged from upstream into this repository.

**If you are upgrading:** please see [UPGRADING.md](UPGRADING.md).

### `db.liveBackup(name, callback)`

<code>liveBackup()</code> is an instance method on an existing database object, used to make a live backup of the current state of the database.

The `name` parameter is a `String`. A successful live backup will result in a backup folder named `backup-:name` inside the `location` folder of the current database.

The `callback` function will be called with no arguments when a live backup was successful, or with a single `error` argument if the backup operation failed for any reason.

## Contributing

[`Level/leveldown-hyper`](https://github.com/Level/leveldown-hyper) is an **OPEN Open Source Project**. This means that:

> Individuals making significant and valuable contributions are given commit-access to the project to contribute as they see fit. This project is more like an open wiki than a standard guarded open source project.

See the [Contribution Guide](https://github.com/Level/community/blob/master/CONTRIBUTING.md) for more details.

## Donate

To sustain [`Level`](https://github.com/Level) and its activities, become a backer or sponsor on [Open Collective](https://opencollective.com/level). Your logo or avatar will be displayed on our 28+ [GitHub repositories](https://github.com/Level), [npm](https://www.npmjs.com/) packages and (soon) [our website](http://leveldb.org). 💖

### Backers

[![Open Collective backers](https://opencollective.com/level/backers.svg?width=890)](https://opencollective.com/level)

### Sponsors

[![Open Collective sponsors](https://opencollective.com/level/sponsors.svg?width=890)](https://opencollective.com/level)

## License

[MIT](LICENSE.md) © 2012-present [Contributors](CONTRIBUTORS.md).

_`leveldown-hyper` builds on the excellent work of the [`HyperLevelDB`](https://github.com/rescrv/HyperLevelDB) team and the LevelDB and Snappy teams from Google and additional contributors. HyperLevelDB, LevelDB and Snappy are issued under the [New BSD License](http://opensource.org/licenses/BSD-3-Clause)._

[level-badge]: http://leveldb.org/img/badge.svg
