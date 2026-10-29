/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The dispatch type 2 is a composite shape's (derived: the dispatch type
 * enum has no record in the executable). */
hknpCompositeShape::hknpCompositeShape() : hknpShape(2), shapeTagCodecInfo(0xffffffff)
{
    flags |= IS_COMPOSITE_SHAPE;
}
