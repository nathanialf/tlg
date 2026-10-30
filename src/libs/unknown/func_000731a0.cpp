/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

const Vec4 *hknpCapsuleShape::FUN_000731a0(Vec4 *buffer, int bufferSize) const /* derived name */
{
    const Vec4 start = a;
    buffer[0] = start;
    const Vec4 end = b;
    const Vec4 delta = _mm_sub_ps(end, start);
    for (int i = 1; i < 7; i++) {
        buffer[i] = _mm_add_ps(start, _mm_mul_ps(delta, _mm_set1_ps(float(i) / 7.0f)));
    }
    buffer[7] = end;
    for (int i = 0; i < 8; i++) {
        reinterpret_cast<int *>(&buffer[i])[3] = i | 0x3f000000;
    }
    return buffer;
}
