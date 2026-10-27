/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpLinearIntegrationClippedCommand::FUN_0003ddd0(hknpWorld *world,
                                                       hkOstream &out) const /* derived name */
{
    out.FUN_00008440("LinearIntegrationClippedCommand Id=")
        .FUN_00008550(bodyId)
        .FUN_00008440(" StolenVel =")
        .FUN_000086b0(stolenVelocity);
}
