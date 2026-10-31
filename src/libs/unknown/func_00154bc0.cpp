/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Modifier16a4580::FUN_00154bc0(CommandOwner00171180 *context, const void *sharedData,
                                   const hknpCdBody *cdBodyA, const hknpCdBody *cdBodyB,
                                   hknpManifoldCollisionCache *cache) const
{
    if (cache->flags22 & 0x40) {
        ManifoldStatusEvent00154bc0 event(cdBodyA->body->byte7f, cdBodyA->body->id,
                                          cdBodyB->body->byte7f, cdBodyB->body->id, 4, cache,
                                          cdBodyA->shapeKey, cdBodyB->shapeKey, HK_NULL);
        event.unknown2 = 1;
        context->dispatcher->exec(event);
    }
}
