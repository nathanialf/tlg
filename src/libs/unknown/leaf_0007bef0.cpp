/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 14 of hkpFixedConstraintData's vtable (address point
 * 0x169c630): the body to notify, as the bit 1 << index in the ball-socket atom's
 * bodiesToNotify, which slot 15 (FUN_0007bf10) reads back. */
void hkpFixedConstraintData::FUN_0007bef0(int bodyIndex) /* derived name */
{
    atoms.ballSocket.bodiesToNotify = static_cast<u8>(1 << bodyIndex);
}
