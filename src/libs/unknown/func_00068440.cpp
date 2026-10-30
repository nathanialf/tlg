/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The keys handed on below a shape (derived names): at most ten, counted
 * as they are added. */
struct ShapeKeyPath00068440 /* derived name */
{
    u32 keys[10];
    int numKeys;
};

void hknpLodShape::FUN_00068440(const u32 *keys, int numKeys,
                                void *argument3) const /* derived name */
{
    const int count = hkMath::min2(numKeys, 10);
    ShapeKeyPath00068440 path;
    path.numKeys = 0;
    for (int i = 0; i < count; i++) {
        path.keys[path.numKeys++] = ((keys[i] + 1) << numShapeKeyBits) - 1;
    }
    const int level = keys[0] >> (32 - numShapeKeyBits);
    shapes[level]->unknownVirtual22(path.keys, count, argument3);
}
