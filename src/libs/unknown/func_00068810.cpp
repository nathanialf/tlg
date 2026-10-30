/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpLodShape::FUN_00068810(const void *argument1, const Slot23Argument *argument2,
                                const void *argument3, const ShapeQuery00038010 &argument4,
                                void *argument5) const /* derived name */
{
    const int level = hkMath::min2(int(argument2->levelOfDetail), numLevelsOfDetail - 1);
    hknpShapeKeyPath keyPath = argument4.keyPath;
    keyPath.appendSubKey(level, numShapeKeyBits);
    ShapeQuery00038010 query(argument4, HK_NULL);
    query.keyPath = keyPath;
    shapes[level]->unknownVirtual23(argument1, argument2, argument3, &query, argument5);
}
