/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: motor 0 of hkpRagdollConstraintData's ragdoll motor atom. */
hkpConstraintMotor *hkpRagdollConstraintData::FUN_0007dfc0() const /* derived name */
{
    return atoms.ragdollMotors.motors[0];
}
