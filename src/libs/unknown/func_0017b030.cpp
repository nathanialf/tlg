/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: waits on two vtable rows (D14): the copy stores
// hkpConstraintMotor's vtable 0x169c750 and hkpLimitedForceConstraintMotor's
// 0x169c710 before the spring-damper's, and neither vtables file names them
// (docs/NOTES.md Round 47).
hkpConstraintMotor *hkpSpringDamperConstraintMotor::FUN_0017b030() const
{
    return new hkpSpringDamperConstraintMotor(*this);
}
