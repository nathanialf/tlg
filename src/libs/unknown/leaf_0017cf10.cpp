/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 7 of hkpWheelFrictionConstraintData's vtable (address
 * point 0x16a5f10): the data is usable once its friction atom has an axle. */
hkBool hkpWheelFrictionConstraintData::FUN_0017cf10() const /* derived name */
{
    return atoms.friction.axle != 0;
}
