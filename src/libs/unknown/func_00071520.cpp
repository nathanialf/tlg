/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* A manifold created: the first time, the event posted; its value reset
 * either way. */
void Modifier169b1a0::FUN_00071520(CommandOwner00171180 *context, const void *sharedData,
                                   const hknpCdBody *cdBodyA, const void *argument4,
                                   const hknpCdBody *cdBodyB, const void *argument6,
                                   ManifoldCache169b1a0 *cache)
{
    if (cache->state == 0) {
        cache->state = 1;
        ManifoldEvent169b1a0 event(cdBodyA->body->byte7f, cdBodyA->body->id, cdBodyB->body->byte7f,
                                   cdBodyB->body->id, ManifoldEvent169b1a0::STATUS_CREATED);
        context->dispatcher->exec(event);
    }
    cache->valueE = 0xffff;
}

/* A manifold gone: when it was created, the event posted. */
void Modifier169b1a0::FUN_000715d0(CommandOwner00171180 *context, const void *sharedData,
                                   ManifoldCache169b1a0 *cache, const void *argument4,
                                   const void *argument5, const hknpCdBody *cdBodyA,
                                   const hknpCdBody *cdBodyB)
{
    const u8 state = cache->state;
    if (state == 1) {
        cache->state = 2;
        ManifoldEvent169b1a0 event(cdBodyA->body->byte7f, cdBodyA->body->id, cdBodyB->body->byte7f,
                                   cdBodyB->body->id, ManifoldEvent169b1a0::STATUS_DESTROYED);
        context->dispatcher->exec(event);
    }
}
