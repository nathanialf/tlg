/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void FUN_0002a7a0(hkMatrix3 &inertia, hkMatrix3 &axesOut)
{
    Vec4 eigenValues;
    FUN_0001b540(inertia, axesOut, eigenValues, 10);
    eigenValues = _mm_max_ps(eigenValues, D_14b2060[35]);
    inertia.col0 = _mm_mul_ps(eigenValues, D_14b2060[29]);
    inertia.col1 = _mm_mul_ps(eigenValues, D_14b2060[30]);
    inertia.col2 = _mm_mul_ps(eigenValues, D_14b2060[31]);
    axesOut.col0 = normalized3(axesOut.col0);
    axesOut.col1 = normalized3(cross3(axesOut.col2, axesOut.col0));
    axesOut.col2 = normalized3(cross3(axesOut.col0, axesOut.col1));
}
