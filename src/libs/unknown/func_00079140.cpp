/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkpLimitedHingeConstraintData::FUN_00079140(hkpConstraintMotor *motor)
{
    if (motor) {
        motor->addReference();
    }
    if (atoms.angMotor.motor) {
        atoms.angMotor.motor->removeReference();
    }
    atoms.angMotor.motor = motor;
}
