/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpShape's finish constructor, then, when the object is being finished,
 * the convex flag and each vertex's index in its w lane (the 0.5 exponent
 * bits over the index): the repeats at the end of the vertices take the
 * index of the last distinct one. */
hknpConvexShape::hknpConvexShape(hkFinishLoadedObjectFlag flag) : hknpShape(flag)
{
    if (flag.finishing) {
        flags |= IS_CONVEX_SHAPE;
        const __m128i all = _mm_set1_epi32(-1);
        int numDistinct = vertices.getSize();
        while (numDistinct >= 2) {
            const Vec4 *v = vertices.beginBytes();
            if (!_mm_testc_si128(
                    _mm_castps_si128(_mm_cmpeq_ps(v[numDistinct - 1], v[numDistinct - 2])), all)) {
                break;
            }
            numDistinct--;
        }
        for (int i = 0; i < vertices.getSize(); i++) {
            const int index = i < numDistinct ? i : numDistinct - 1;
            reinterpret_cast<int *>(&vertices.beginBytes()[i])[3] = index | 0x3f000000;
        }
    }
}
