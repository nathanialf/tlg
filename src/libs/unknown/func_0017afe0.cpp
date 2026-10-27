/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkpSpringDamperConstraintMotor::hkpSpringDamperConstraintMotor()
{
    type = TYPE_SPRING_DAMPER;
    minForce = -1000000.0f;
    maxForce = 1000000.0f;
    springConstant = 0.0f;
    springDamping = 0.0f;
}
