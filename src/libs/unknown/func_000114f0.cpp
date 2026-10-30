/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkQsTransform::FUN_000114f0(hkMatrix4 &out) const
{
    hkMatrix3 rotationMatrix;
    rotationMatrix.FUN_0000bd30(rotation);
    hkMatrix3 scaleMatrix;
    scaleMatrix.col0 = _mm_mul_ps(scale, D_14b2060[29]);
    scaleMatrix.col1 = _mm_mul_ps(scale, D_14b2060[30]);
    scaleMatrix.col2 = _mm_mul_ps(scale, D_14b2060[31]);
    hkMatrix3 rotationScale;
    rotationScale.FUN_0001a9f0(rotationMatrix, scaleMatrix);
    hkTransform transform;
    transform.rotation = rotationScale;
    transform.translation = translation;
    transform.FUN_00010a10(out);
}
