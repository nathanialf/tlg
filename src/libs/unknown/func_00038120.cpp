/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 8 of hknpMaskedShape's vtable (0x1693ad0) returns its
 * mutation signals. The same body fills slot 8 of the vtable at 0x16967c0
 * and the vtable slot at 0x16b1770. */
hknpShapeSignals *hknpMaskedShape::FUN_00038120() /* derived name */
{
    return &mutationSignals;
}
