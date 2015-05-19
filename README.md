LevelDOWNHyper
=========

<img alt="LevelDB Logo" height="100" src="http://leveldb.org/img/logo.svg">

A Low-level Node.js LevelDB binding
-------------------------

[![Build Status](https://secure.travis-ci.org/Level/leveldown-hyper.png)](http://travis-ci.org/Level/leveldown-hyper)

[![NPM](https://nodei.co/npm/leveldown-hyper.png?stars&downloads&downloadRank)](https://nodei.co/npm/leveldown-hyper/) [![NPM](https://nodei.co/npm-dl/leveldown-hyper.png?months=6&height=3)](https://nodei.co/npm/leveldown-hyper/)

LevelDOWNHyper is a fork of LevelDOWN and uses [`HyperLevelDB`](https://github.com/rescrv/HyperLevelDB) as backend. It extends the LevelDOWN api with functionality to do live backups. This README only documents the `liveBackup()` method. For a complete reference we refer to [`LevelDOWN`](https://github.com/Level/leveldown).

LevelDOWN can be considered an upstream repository to LevelDOWNHyper and any common logic and bug fixes will be merged from upstream into this repository.

--------------------------------------------------------
### liveBackup(name, callback)
<code>liveBackup()</code> is an instance method on an existing database object, used to make a live backup of the current state of the database.

The `name` parameter is a `String`. A successful live backup will result in a backup folder named `backup-:name` inside the `location` folder of the current database.

The `callback` function will be called with no arguments when a live backup was successful, or with a single `error` argument if the backup operation failed for any reason.

Community
---------

LevelDOWNHyper is an **OPEN Open Source Project**. This means that:

> Individuals making significant and valuable contributions are given commit-access to the project to contribute as they see fit. This project is more like an open wiki than a standard guarded open source project.

See the [contribution guide](https://github.com/Level/community/blob/master/CONTRIBUTING.md) for more details.

License &amp; Copyright
-------------------

Copyright (c) 2012-2015 LevelDOWNHyper [contributors](https://github.com/level/community#contributors).

LevelDOWNHyper is licensed under the MIT license. All rights not explicitly granted in the MIT license are reserved. See the included `LICENSE.md` file for more details.

*LevelDOWNHyper builds on the excellent work of the [`HyperLevelDB`](https://github.com/rescrv/HyperLevelDB) team and the LevelDB and Snappy teams from Google and additional contributors. HyperLevelDB, LevelDB and Snappy are issued under the [New BSD Licence](http://opensource.org/licenses/BSD-3-Clause).*
