/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* A matrix set to the identity a column at a time, rows 29 to 32 of the
 * constant table, as hkMatrix4's setIdentity does. derived name. */
static inline void setIdentity(Mat4 &m) /* derived name */
{
    m.r[0] = D_14b2060[29];
    m.r[1] = D_14b2060[30];
    m.r[2] = D_14b2060[31];
    m.r[3] = D_14b2060[32];
}

/* derived name: the inverse matrices from the start index on copied out to
 * the caller's, or the identity for each when the set holds none. */
void FUN_000237b0(const hkIndexedTransformSet *self, int startIndex, Mat4 *matrices,
                  int numMatrices) /* derived name */
{
    if (self->inverseMatrices.size > 0) {
        if (numMatrices > 0) {
            hkString::memCpy16(matrices, &self->inverseMatrices.data[startIndex],
                               numMatrices * (sizeof(Mat4) / sizeof(Vec4)));
        }
    } else {
        for (int i = 0; i < numMatrices; i++) {
            setIdentity(matrices[i]);
        }
    }
}
