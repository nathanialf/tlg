/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int hknpCompoundShapeInternalsKeyMask::FUN_00033d30(hknpShapeInstanceId instanceId) const
{
    const int index = shape->instances.elements[instanceId.value].getIndex();
    return (filter[index / 32] & (1 << (index & 31))) != 0;
}
