/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpLodShape::FUN_000686c0(const void *argument1, const Slot23Argument *argument2,
                                const void *argument3, const void *argument4,
                                const ShapeQuery00038010 &argument5, const void *argument6,
                                void *argument7) const /* derived name */
{
    const int level = hkMath::min2(int(argument2->levelOfDetail), numLevelsOfDetail - 1);
    hknpShapeKeyPath keyPath = argument5.keyPath;
    keyPath.appendSubKey(level, numShapeKeyBits);
    ShapeQuery00038010 query(argument5, HK_NULL);
    query.keyPath = keyPath;
    shapes[level]->unknownVirtual26(argument1, argument2, argument3, argument4, &query, argument6,
                                    argument7);
}
