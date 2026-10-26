/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the angular motor of an index; all the motors are asked for
 * by the twist motor. */
hkpConstraintMotor *hkp6DofConstraintData::FUN_0017bb20(MotorIndex index) const
{
    if (index == MOTOR_ALL) {
        return blueprints.ragdollMotors.motors[MOTOR_TWIST];
    }
    return blueprints.ragdollMotors.motors[index];
}
