/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Modifier16a4e60::FUN_0015db70(const CommandOwner00171180 *context,
                                   const ImpulseClippedInput0015db70 *input,
                                   const float &impulse) const /* derived name */
{
    const hknpBodyId idA(FUN_00010650(input->pair));
    const hknpBodyId idB(FUN_00034840(input->pair));
    const hknpBody *bodies = context->bodyView->bodies;
    const hknpBody &bodyA = bodies[idA.value];
    const hknpBody &bodyB = bodies[idB.value];
    ImpulseEvent0015db70 event(bodyA.byte7f, bodyA.id, bodyB.byte7f, bodyB.id);
    event.pair = input->pair;
    event.impulse = impulse;
    context->dispatcher->exec(event);
}
