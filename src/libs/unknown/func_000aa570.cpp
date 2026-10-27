/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int FUN_000aa570(hkMeshSection::PrimitiveType primitiveType, int numPrimitives) /* derived name */
{
    switch (primitiveType) {
    case hkMeshSection::PRIMITIVE_TYPE_POINT_LIST:
        return numPrimitives;
    case hkMeshSection::PRIMITIVE_TYPE_LINE_LIST:
        return numPrimitives * 2;
    case hkMeshSection::PRIMITIVE_TYPE_TRIANGLE_LIST:
        return numPrimitives * 3;
    case hkMeshSection::PRIMITIVE_TYPE_TRIANGLE_STRIP:
        return numPrimitives + 2;
    default:
        return 0;
    }
}
