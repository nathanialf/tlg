/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 14 of hkpRagdollConstraintData's vtable (address point
 * 0x169d0e0): the body to notify, as the bit 1 << index in the ball-socket atom's
 * bodiesToNotify, which slot 15 (FUN_0007dcd0) reads back. */
void hkpRagdollConstraintData::FUN_0007dcb0(int bodyIndex) /* derived name */
{
    atoms.ballSocket.bodiesToNotify = static_cast<u8>(1 << bodyIndex);
}
