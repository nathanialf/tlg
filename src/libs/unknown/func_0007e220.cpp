/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkpRagdollConstraintData::FUN_0007e220(void *runtimeIn, hkBool isEnabled) /* derived name */
{
    atoms.ragdollMotors.isEnabled = isEnabled;
    atoms.angFriction.isEnabled = !isEnabled;
    Runtime *runtime = static_cast<Runtime *>(runtimeIn);
    if (runtime) {
        for (int i = 0; i < 12; i++) {
            runtime->solverResults[i].init();
        }
    }
}
