/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Modifier16a5020::FUN_001622a0(CommandOwner00171180 *context, const void *sharedData,
                                   const hknpCdBody *cdBodyA, const hknpCdBody *cdBodyB,
                                   hknpManifoldCollisionCache *cache) const
{
    const u16 flags = cache->flags22;
    if (flags & 8) {
        ManifoldEvent169b1a0 event(cdBodyA->body->byte7f, cdBodyA->body->id, cdBodyB->body->byte7f,
                                   cdBodyB->body->id, 1, ManifoldEvent169b1a0::STATUS_DESTROYED,
                                   cdBodyA->shapeKey, cdBodyB->shapeKey);
        context->dispatcher->exec(event);
    }
    cache->flags22 = flags & ~0x18;
}
