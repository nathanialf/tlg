/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 43 of 43 instructions in place but the loads' order and registers: the base
// loads the bodies' bytes and the cache's ids first and the two shape keys last (into r9d and
// ecx, freed by then), this compile the keys first; the stores and the IR's load order do not
// decide it (reordered IR loads give the same schedule, NOTES Round 61B).
void Modifier16a4580::FUN_00154ca0(CommandOwner00171180 *context, const void *sharedData,
                                   const hknpCdBody *cdBodyA, const hknpCdBody *cdBodyB,
                                   const hknpManifoldCollisionCache *cache) const
{
    if (cache->flags22 & 0x80) {
        ManifoldStatusEvent00154bc0 event(cdBodyA->body->byte7f, cache->bodyIdA,
                                          cdBodyB->body->byte7f, cache->bodyIdB, 8, HK_NULL,
                                          cdBodyA->shapeKey, cdBodyB->shapeKey);
        event.unknown2 = 1;
        context->dispatcher->exec(event);
    }
}
