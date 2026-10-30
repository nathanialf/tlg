/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpShapeInstance::FUN_0003eb70(const hknpShape *newShape)
{
    shape = newShape;
    if (newShape) {
        setShapeSize(newShape->unknownVirtual6());
    } else {
        setShapeSize(0);
    }
}
