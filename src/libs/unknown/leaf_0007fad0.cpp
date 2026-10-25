/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 9 of hkpLinearParametricCurve's vtable (address point
 * 0x169d8a0) returns the parameter at the end of the curve, one less than
 * the number of its points. */
float hkpLinearParametricCurve::FUN_0007fad0() const /* derived name */
{
    return static_cast<float>(points.size - 1);
}
