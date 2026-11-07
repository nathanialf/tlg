/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the inverse of a rigid transform out of line: the rotation
 * transposed (as hkMatrix3's FUN_0001a980 transposes in place), the
 * translation negated and carried back through it. */
void hkTransform::FUN_00010ad0(const hkTransform &t)
{
    setInverse(t);
}
