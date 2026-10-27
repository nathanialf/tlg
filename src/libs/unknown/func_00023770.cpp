/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the matrices from the start index on copied out to the
 * caller's (the memory mesh body's FUN_00023110 forwards here). */
void FUN_00023770(const hkIndexedTransformSet *self, int startIndex, Mat4 *matrices,
                  int numMatrices) /* derived name */
{
    if (numMatrices > 0) {
        hkString::memCpy16(matrices, &self->matrices.data[startIndex],
                           numMatrices * (sizeof(Mat4) / sizeof(Vec4)));
    }
}
