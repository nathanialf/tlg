/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 8 of hknpCompoundShape's vtable (address point
 * 0x1697910), kept by the static and dynamic compound shapes: only a
 * mutable shape hands out its mutation signals. */
hknpShapeSignals *hknpCompoundShape::FUN_00041890() /* derived name */
{
    return isMutable ? &mutationSignals : 0;
}
