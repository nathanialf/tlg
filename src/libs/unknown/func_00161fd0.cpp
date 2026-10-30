/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Whether a body raising trigger events is a trigger of the contact
 * solver's type, its material's type read into a value of its own (D30:
 * the base keeps the byte's load apart from the compare). derived name. */
static bool isContactSolverTrigger(int flags, const hknpCdBody *cdBody) /* derived name */
{
    if (flags & hknpBody::RAISE_TRIGGER_EVENTS) {
        const u8 triggerType = cdBody->material->triggerType;
        return triggerType == hknpMaterial::TRIGGER_TYPE_CONTACT_SOLVER;
    }
    return false;
}

void Modifier16a5020::FUN_00161fd0(CommandOwner00171180 *context, const void *sharedData,
                                   const hknpCdBody *cdBodyA, const hknpCdBody *cdBodyB,
                                   ManifoldCreatedInput *input) const
{
    hknpManifoldCollisionCache *cache = input->collisionCache;
    cache->flags0c |= 4;
    const int flagsA = cdBodyA->body->flags;
    const int flagsB = cdBodyB->body->flags;
    if ((flagsA | flagsB) & hknpBody::RAISE_TRIGGER_EVENTS) {
        if (isContactSolverTrigger(flagsA, cdBodyA) || isContactSolverTrigger(flagsB, cdBodyB)) {
            cache->maxImpulse.value = 0;
            cache->fractionOfClippedImpulseToApply = 0;
        } else {
            cache->enabledModifiers |= 1 << 9;
            ManifoldEvent169b1a0 event(
                cdBodyA->body->byte7f, cdBodyA->body->id, cdBodyB->body->byte7f, cdBodyB->body->id,
                1, ManifoldEvent169b1a0::STATUS_CREATED, cdBodyA->shapeKey, cdBodyB->shapeKey);
            context->dispatcher->exec(event);
            cache->flags22 |= 8;
        }
    } else {
        cache->enabledModifiers |= 1 << 9;
    }
}
