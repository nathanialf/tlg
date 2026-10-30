/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Modifier16a4fa0::FUN_00161f10(CommandOwner00171180 *context, const void *sharedData,
                                   const hknpCdBody *cdBodyA, const hknpCdBody *cdBodyB,
                                   const hknpManifoldCollisionCache *cache) const
{
    if ((cache->flags22 & 5) == 5) {
        BodyPairEvent00161f10 event(cdBodyA->body->byte7f, cdBodyA->body->id, cdBodyB->body->byte7f,
                                    cdBodyB->body->id);
        context->dispatcher->exec(event);
    }
}
