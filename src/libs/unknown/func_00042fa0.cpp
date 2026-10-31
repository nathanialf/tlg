/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpConvexShape::unknownVirtual7(const Mat4 &transform, hkAabb &aabbOut) const
{
    Vec4 minimum = D_14b2060[33];
    Vec4 maximum = _mm_xor_ps(minimum, _mm_set1_ps(-0.0f));
    const int numVertices = vertices.getSize();
    if (numVertices) {
        const Vec4 *v = vertices.begin();
        const Vec4 c0 = transform.r[0];
        const Vec4 c1 = transform.r[1];
        const Vec4 c2 = transform.r[2];
        for (int i = 0; i < numVertices; i += 4) {
            const Vec4 t0 = combineColumns(c0, c1, c2, v[0]);
            const Vec4 t1 = combineColumns(c0, c1, c2, v[1]);
            const Vec4 t2 = combineColumns(c0, c1, c2, v[2]);
            const Vec4 t3 = combineColumns(c0, c1, c2, v[3]);
            minimum = _mm_min_ps(_mm_min_ps(_mm_min_ps(_mm_min_ps(minimum, t0), t1), t2), t3);
            maximum = _mm_max_ps(_mm_max_ps(_mm_max_ps(_mm_max_ps(maximum, t0), t1), t2), t3);
            v += 4;
        }
    }
    const Vec4 translation = transform.r[3];
    aabbOut.min = _mm_add_ps(minimum, translation);
    aabbOut.max = _mm_add_ps(maximum, translation);
    const Vec4 radius = _mm_set1_ps(convexRadius);
    aabbOut.max = _mm_add_ps(aabbOut.max, radius);
    aabbOut.min = _mm_sub_ps(aabbOut.min, radius);
}
