/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the matrices from the start index on set from the caller's
 * (the memory mesh body's FUN_00023100 forwards here). */
void FUN_00023700(hkIndexedTransformSet *self, int startIndex, const Mat4 *matrices,
                  int numMatrices) /* derived name */
{
    if (numMatrices > 0) {
        hkString::memCpy16(&self->matrices.data[startIndex], matrices,
                           numMatrices * (sizeof(Mat4) / sizeof(Vec4)));
    }
}
