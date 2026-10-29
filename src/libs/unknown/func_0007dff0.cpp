/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkpRagdollConstraintData::FUN_0007dff0(hkpConstraintMotor *motor)
{
    if (motor) {
        motor->addReference();
    }
    if (atoms.ragdollMotors.motors[0]) {
        atoms.ragdollMotors.motors[0]->removeReference();
    }
    atoms.ragdollMotors.motors[0] = motor;
}
