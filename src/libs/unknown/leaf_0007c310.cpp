/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 14 of hkpBallAndSocketConstraintData's vtable (address
 * point 0x169c7e0) stores the body to notify as the bit 1 << index, which
 * slot 15 (FUN_0007c320) reads back. */
void hkpBallAndSocketConstraintData::FUN_0007c310(int bodyIndex) /* derived name */
{
    atoms.ballSocket.bodiesToNotify = 1 << bodyIndex;
}
