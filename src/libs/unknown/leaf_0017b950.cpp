/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 15 of hkp6DofConstraintData's vtable (address
 * point 0x16a5d30) returns the index of the body to notify, kept as the bit
 * 1 << index in the ball-socket atom's bodiesToNotify. */
u8 hkp6DofConstraintData::FUN_0017b950() const /* derived name */
{
    return blueprints.ballSocket.bodiesToNotify >> 1;
}
