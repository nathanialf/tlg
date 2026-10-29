/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkpPrismaticConstraintData::FUN_0007e7c0(hkpConstraintMotor *motor)
{
    if (motor) {
        motor->addReference();
    }
    if (atoms.motor.motor) {
        atoms.motor.motor->removeReference();
    }
    atoms.motor.motor = motor;
}
