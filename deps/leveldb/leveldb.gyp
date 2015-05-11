{'targets': [{
    'target_name': 'leveldb-hyper'
  , 'variables': {
        'ldbversion': 'hyper'
      , 'base': 'leveldb-hyper-1.0.2'
      , 'conditions': [
            ['OS=="linux"',   {'os_include': 'linux'}]
          , ['OS=="mac"',     {'os_include': 'mac'}]
        ]
    }
  , 'type': 'static_library'
		# Overcomes an issue with the linker and thin .a files on SmartOS
  , 'standalone_static_library': 1
  , 'dependencies': [
        '../snappy/snappy.gyp:snappy'
    ]
  , 'direct_dependent_settings': {
        'include_dirs': [
            '<(base)/include/'
          , '<(base)/port/'
          , '<(base)/util'
          , '<(base)/'
        ]
    }
  , 'defines': [
        'SNAPPY=1'
      , 'HAVE_CONFIG_H=1'
    ]
  , 'include_dirs': [
        'leveldb-hyper-conf/<(os_include)/'
      , '<(base)/'
      , '<(base)/include/'
    ]
  , 'conditions': [
        ['OS == "win"', {
            'include_dirs': [
                '<(base)/port/win'
              , 'port-libuv/'
            ]
          , 'defines': [
                'LEVELDB_PLATFORM_UV=1'
              , 'NOMINMAX=1'
              , '_HAS_EXCEPTIONS=0'
            ]
          , 'sources': [
                'port-libuv/port_uv.cc'
              , 'port-libuv/env_win.cc'
              , 'port-libuv/win_logger.cc'
            ]
          , 'msvs_settings': {
                'VCCLCompilerTool': {
                    'RuntimeTypeInfo': 'false'
                  , 'EnableFunctionLevelLinking': 'true'
                  , 'ExceptionHandling': '2'
                  , 'DisableSpecificWarnings': [ '4355', '4530' ,'4267', '4244' ]
                }
            }
        }, { # OS != "win"
            'sources': [
                '<(base)/port/port_posix.cc'
              , '<(base)/port/port_posix.h'
              , '<(base)/util/env_posix.cc'
            ]
          , 'defines': [
                'LEVELDB_PLATFORM_POSIX=1'
            ]
          , 'ccflags': [
                '-fno-builtin-memcmp'
              , '-fPIC'
            ]
          , 'cflags': [ '-std=c++0x' ]
          , 'cflags!': [ '-fno-tree-vrp' ]
        }]
      , ['OS != "win" and OS != "freebsd"', {
            'cflags': [
                '-Wno-sign-compare'
              , '-Wno-unused-but-set-variable'
              , '-Wno-unused-variable'
              , '-Wno-maybe-uninitialized'
              , '-Wno-type-limits'
              , '-Wno-reorder'
            ]
        }]
      , ['OS == "linux" or OS == "freebsd" or OS == "solaris"', {
            'cflags_cc+': [
                '-frtti'
            ]
        }]
      , ['OS == "linux"', {
            'defines': [
                'OS_LINUX=1'
            ]
          , 'libraries': [
                '-lpthread'
            ]
          , 'ccflags': [
                '-pthread'
            ]
        }]
      , ['OS == "freebsd"', {
            'defines': [
                'OS_FREEBSD=1'
              , '_REENTRANT=1'
            ]
          , 'libraries': [
                '-lpthread'
            ]
          , 'ccflags': [
                '-pthread'
            ]
          , 'cflags': [
                '-Wno-sign-compare'
            ]
        }]
      , ['OS == "solaris"', {
            'defines': [
                'OS_SOLARIS=1'
              , '_REENTRANT=1'
            ]
          , 'libraries': [
                '-lrt'
              , '-lpthread'
            ]
          , 'ccflags': [
                '-pthread'
            ]
        }]
      , ['OS == "mac"', {
            'defines': [
                'OS_MACOSX=1'
            ]
          , 'libraries': []
          , 'ccflags': []
          , 'xcode_settings': {
                'WARNING_CFLAGS': [
                    '-Wno-sign-compare'
                  , '-Wno-unused-variable'
                  , '-Wno-unused-function'
                ]
            }
        }]
    ]
  , 'sources': [
        '<(base)/util/bloom.cc'
      , '<(base)/util/env_posix.cc'
      , '<(base)/util/env.cc'
      , '<(base)/util/histogram.cc'
      , '<(base)/util/coding.cc'
      , '<(base)/util/hash.cc'
      , '<(base)/util/logging.cc'
      , '<(base)/util/filter_policy.cc'
      , '<(base)/util/arena.cc'
      , '<(base)/util/cache.cc'
      , '<(base)/util/comparator.cc'
      , '<(base)/util/status.cc'
      , '<(base)/util/options.cc'
      , '<(base)/util/crc32c.cc'
      , '<(base)/db/c.cc'
      , '<(base)/db/log_reader.cc'
      , '<(base)/db/repair.cc'
      , '<(base)/db/table_cache.cc'
      , '<(base)/db/log_writer.cc'
      , '<(base)/db/dbformat.cc'
      , '<(base)/db/write_batch.cc'
      , '<(base)/db/db_impl.cc'
      , '<(base)/db/memtable.cc'
      , '<(base)/db/leveldb_main.cc'
      , '<(base)/db/version_edit.cc'
      , '<(base)/db/version_set.cc'
      , '<(base)/db/builder.cc'
      , '<(base)/db/filename.cc'
      , '<(base)/db/db_iter.cc'
      , '<(base)/db/replay_iterator.cc'
      , '<(base)/port/port_posix.cc'
      , '<(base)/table/merger.cc'
      , '<(base)/table/filter_block.cc'
      , '<(base)/table/block_builder.cc'
      , '<(base)/table/iterator.cc'
      , '<(base)/table/table_builder.cc'
      , '<(base)/table/format.cc'
      , '<(base)/table/table.cc'
      , '<(base)/table/block.cc'
      , '<(base)/table/two_level_iterator.cc'
    ]
}]}
