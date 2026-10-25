/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 15 of hkpRagdollConstraintData's vtable (address
 * point 0x169d0e0) returns the index of the body to notify, kept as the bit
 * 1 << index in the ball-socket atom's bodiesToNotify. */
u8 hkpRagdollConstraintData::FUN_0007dcd0() const /* derived name */
{
    return atoms.ballSocket.bodiesToNotify >> 1;
}
