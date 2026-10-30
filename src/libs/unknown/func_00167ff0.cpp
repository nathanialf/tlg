/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The command writer deleted, the stream's blocks given back to the second
 * cache, the context's own caches freed (the first only when it is not the
 * second, so a shared one is freed once) and cleared, then the three
 * records given back to the world's +0x380 object (its slot 9). The first
 * cache is not read. */
void hknpWorldContextPool::Context::FUN_00167ff0(BlockCache *cacheA, BlockCache *cacheB)
{
    delete commandWriter;
    commandWriter = 0;
    stream.FUN_00094990(cacheB);
    BlockCache *remaining = cache250;
    if (cache250 != cache258) {
        delete cache250;
        remaining = cache258;
    }
    delete remaining;
    cache260 = 0;
    cache258 = 0;
    cache250 = 0;
    hknpWorldObject380 *object = static_cast<hknpWorldObject380 *>(modifierManager->objects4e0[0]);
    object->FUN_00031170(records268, 3);
}
