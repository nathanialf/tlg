/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

InplaceTriangleShape00078160::InplaceTriangleShape00078160(float convexRadius)
{
    hkString::memCpy16(buffer, D_57c8818->triangleShapeStorage.buffer, sizeof(buffer) / 16);
    getTriangleShape()->convexRadius = convexRadius;
}
