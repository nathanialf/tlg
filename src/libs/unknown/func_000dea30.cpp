/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hknpShapeKeyMask *hknpStaticCompoundShape::FUN_000dea30() const /* derived name */
{
    return new hknpStaticCompoundShapeKeyMask(this);
}
