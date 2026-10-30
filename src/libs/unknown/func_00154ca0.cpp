/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Modifier16a4580::FUN_00154ca0(CommandOwner00171180 *context, const void *sharedData,
                                   const hknpCdBody *cdBodyA, const hknpCdBody *cdBodyB,
                                   const hknpManifoldCollisionCache *cache) const
{
    if (cache->flags22 & 0x80) {
        const u32 byteA = cdBodyA->body->byte7f;
        const u32 idA = cache->bodyIdA;
        const u32 byteB = cdBodyB->body->byte7f;
        const u32 idB = cache->bodyIdB;
        ManifoldStatusEvent00154bc0 event(byteA, idA, byteB, idB, 8, HK_NULL, cdBodyA->shapeKey,
                                          cdBodyB->shapeKey);
        event.unknown2 = 1;
        context->dispatcher->exec(event);
    }
}
