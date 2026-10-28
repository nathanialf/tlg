/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The properties destroyed and freed only when the shape was allocated: a
 * shape loaded in place (no size recorded) does not own them. */
hknpShape::~hknpShape()
{
    if (properties && (memSizeAndRefCount & 0xffff0000) != 0) {
        delete properties;
    }
    properties = 0;
}
