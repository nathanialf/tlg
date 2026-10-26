/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 14 of hkp6DofConstraintData's vtable (address point
 * 0x16a5d30): the body to notify, as the bit 1 << index in the ball-socket atom's
 * bodiesToNotify, which slot 15 (FUN_0017b950) reads back. */
void hkp6DofConstraintData::FUN_0017b930(int bodyIndex) /* derived name */
{
    blueprints.ballSocket.bodiesToNotify = static_cast<u8>(1 << bodyIndex);
}
