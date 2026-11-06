/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Modifier16a5020::FUN_001623a0(CommandOwner00171180 *context,
                                   const SolverCallbackInput001623a0 *input,
                                   const Vec4 *contactImpulses, float frictionFactor) const
{
    hknpManifoldCollisionCache *cache = input->collisionCache;
    const u32 bodyIdA = FUN_00010650(input->record);
    const u32 bodyIdB = FUN_00034840(input->record);
    const int shapeKeyA = FUN_00034850(input->record);
    const int shapeKeyB = FUN_00034870(input->record);
    const int value = input->value18;
    const u16 flags = cache->flags22;
    const u16 exited = flags & 0x10;
    if (!(flags & 8)) {
        if (value != 0) {
            const hknpBody *bodies = context->bodyView->bodies;
            hknpValidateTriggerEventCommand command(bodies[bodyIdA].byte7f, bodies[bodyIdA].id,
                                                    bodies[bodyIdB].byte7f, bodies[bodyIdB].id);
            command.record = input->record;
            context->dispatcher->exec(command);
        }
    } else if (value == 0 && !exited) {
        const hknpBody *bodies = context->bodyView->bodies;
        ManifoldEvent169b1a0 event(bodies[bodyIdA].byte7f, bodies[bodyIdA].id,
                                   bodies[bodyIdB].byte7f, bodies[bodyIdB].id, 2,
                                   ManifoldEvent169b1a0::STATUS_DESTROYED, shapeKeyA, shapeKeyB);
        context->dispatcher->exec(event);
        cache->flags22 &= ~0x18;
    }
    input->collisionCache->resetSolverRecord();
}
