import * as Abstract from 'abstract-leveldown';

declare namespace hyper {
  export interface LevelDownHyper<TKey, TValue>
    extends Abstract.LevelDOWN<
    TKey,
    TValue,
    LevelDownHyperOptions,
    LevelDownHyperDBPutOptions,
    LevelDownHyperGetOptions,
    LevelDownHyperDeleteOptions,
    LevelDownHyperIteratorOptions<TKey, TValue>,
    LevelDownHyperBatchOptions> {
    compactRange(start: TKey, end: TKey, cb: (err?: any) => void): void;
    getProperty(property: string): string;
    iterator(options?: LevelDownHyperIteratorOptions<TKey, TValue>): LevelDownHyperIterator<TKey>
    destroy(location: string, cb: (err?: any) => void): void;
    repair(location: string, cb: (err?: any) => void): void;
    liveBackup(name:string, cb: (err?: any) => void): void;
  }

  export interface LevelDownHyperOptions {

  }

  export interface LevelDownHyperDBPutOptions {
    sync?: boolean
  }

  export interface LevelDownHyperGetOptions {
    fillCache?: boolean;
    asBuffer?: boolean;
  }

  export interface LevelDownHyperDeleteOptions {
    sync?: boolean;
  }

  export interface LevelDownHyperIteratorOptions<K, V> {
    gt?: K;
    gte?: K;
    lt?: K;
    lte?: K;
    reverse?: boolean;
    keys?: boolean;
    values?: boolean;
    limit?: number;
    keyAsBuffer?: boolean;
    valueAsBuffer?: boolean;
  }

  export interface LevelDownHyperBatchOptions {
    sync?: boolean;
  }

  export interface LevelDownHyperIterator<TKey> extends Abstract.Iterator {
    seek(key: TKey);
    binding: any;
    cache: any;
    finished: any;
    fastFuture: any;
  }
}
declare function hyper<
  TKey=any,
  TValue=any
  >(location: string)
  : hyper.LevelDownHyper<TKey, TValue>;


export = hyper;