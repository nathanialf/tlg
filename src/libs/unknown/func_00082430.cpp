/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The constant recovery velocity is stored before the proportional one
 * (0x82465, 0x8246c). */
hkpPositionConstraintMotor::hkpPositionConstraintMotor()
{
    type = TYPE_POSITION;
    minForce = -1000000.0f;
    maxForce = 1000000.0f;
    tau = 0.8f;
    damping = 1.0f;
    constantRecoveryVelocity = 1.0f;
    proportionalRecoveryVelocity = 2.0f;
}
