/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 8 of hknpScaledConvexShape's vtable (address point
 * 0x16a54b0) returns the signals at +0x60. */
hknpShapeSignals *hknpScaledConvexShape::FUN_0016ced0() /* derived name */
{
    return &mutationSignals;
}
