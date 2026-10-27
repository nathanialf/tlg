/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the motor enabled or not, the friction the opposite, and
 * the runtime's motor and friction results reset. */
void hkpLimitedHingeConstraintData::FUN_00079100(void *runtimeIn, hkBool isEnabled)
{
    atoms.angMotor.isEnabled = isEnabled;
    atoms.angFriction.isEnabled = !isEnabled;
    Runtime *runtime = static_cast<Runtime *>(runtimeIn);
    if (runtime) {
        for (int i = 0; i < 4; i++) {
            runtime->solverResults[i].init();
        }
    }
}
