/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 15 of hkpBallAndSocketConstraintData's vtable (address
 * point 0x169c7e0) returns the index of the body to notify, which slot 14
 * (0x7c310) stores as the bit 1 << index. */
u8 hkpBallAndSocketConstraintData::FUN_0007c320() const /* derived name */
{
    return atoms.ballSocket.bodiesToNotify >> 1;
}
