/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 7 of hkpPulleyConstraintData's vtable (address point
 * 0x169f600): the data is valid unless the rope's length or the leverage on
 * body B is not positive. */
hkBool hkpPulleyConstraintData::FUN_000825a0() const /* derived name */
{
    return !(atoms.pulley.ropeLength <= 0.0f || atoms.pulley.leverageOnBodyB <= 0.0f);
}
