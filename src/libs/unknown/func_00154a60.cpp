/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Modifier16a4580::FUN_00154a60(CommandOwner00171180 *context, const void *sharedData,
                                   const hknpCdBody *cdBodyA, const hknpCdBody *cdBodyB,
                                   const hknpManifold *manifold) const
{
    hknpManifoldCollisionCache *cache = manifold->collisionCache;
    if (manifold->flag93 || (cache->flags22 & 0x20)) {
        ManifoldStatusEvent00154bc0 event(
            cdBodyA->body->byte7f, cdBodyA->body->id, cdBodyB->body->byte7f, cdBodyB->body->id,
            manifold->flag93 ? 1 : 2, cache, cdBodyA->shapeKey, cdBodyB->shapeKey, manifold);
        event.unknown2 = 1;
        context->dispatcher->exec(event);
    }
}
