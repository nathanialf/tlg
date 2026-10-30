/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int hknpLodShape::FUN_00068380(void *argument1, int argument2, int key,
                               const ShapeKeyQuery000380b0 &query) const
{
    const int level = hkMath::min2(query.levelOfDetail, numLevelsOfDetail - 1);
    ShapeKeyQuery000380b0 levelQuery = query; /* derived name */
    levelQuery.appendSubKey(level, numShapeKeyBits);
    return shapes[level]->unknownVirtual21(argument1, argument2, ((key + 1) << numShapeKeyBits) - 1,
                                           levelQuery);
}
