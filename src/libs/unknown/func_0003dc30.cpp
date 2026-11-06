/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpContactImpulseClippedEvent::FUN_0003dc30(hknpWorld *world, hkOstream &out) const
{
    Output0002b3b0 output;
    const int bodyA = FUN_00010650(record);
    const int bodyB = FUN_00034840(record);
    const hknpMotion *motionA =
        &world->motionManager.motions[world->bodyManager.bodies[bodyA].motionId];
    const hknpMotion *motionB =
        &world->motionManager.motions[world->bodyManager.bodies[bodyB].motionId];
    FUN_00034920(record, &world->solverInfo, motionA, motionB, &output);
    out.FUN_00008440("hknpContactImpulseClippedEvent bodyIds=")
        .FUN_00008550(bodyIdA)
        .FUN_00008440(",")
        .FUN_00008550(bodyIdB)
        .FUN_00008440(" normal=")
        .FUN_000086b0(output.vector10)
        .FUN_00008440(" pos0=")
        .FUN_000086b0(output.vectors[0])
        .FUN_00008440(" pos1=")
        .FUN_000086b0(output.vectors[1])
        .FUN_00008440(" pos2=")
        .FUN_000086b0(output.vectors[2])
        .FUN_00008440(" pos3=")
        .FUN_000086b0(output.vectors[3]);
}
