/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: the springs' stores: the base merges the forces at +0x10 and
// +0x14 into one 8-byte store and keeps the zeros at +0x18 and +0x1c apart;
// this merges both pairs (docs/NOTES.md, Round 32).
hkpSpringDamperConstraintMotor::hkpSpringDamperConstraintMotor()
{
    type = TYPE_SPRING_DAMPER;
    minForce = -1000000.0f;
    maxForce = 1000000.0f;
    springConstant = 0.0f;
    springDamping = 0.0f;
}
