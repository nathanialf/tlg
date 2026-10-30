/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpWorldContextPool::FUN_0016feb0()
{
    Context &first = contexts[0];
    for (int i = 1; i < numUsed0 + numUsed4; i++) {
        contexts[i].FUN_00167ff0(first.cache250, first.cache258);
    }
    if (cache) {
        stream.FUN_00094990(cache);
        delete cache;
        cache = 0;
    }
    first.FUN_00167ff0(first.cache250, first.cache258);
    numUsed0 = 0;
    numUsed4 = 0;
}
