/* SIMD types shared by the rebuilt sources. The engine's math stores rows as
 * 16-byte-aligned vectors of four floats and moves them with aligned SSE
 * loads and stores. */
#ifndef TLG_SIMD_H
#define TLG_SIMD_H

#include <xmmintrin.h>

typedef __m128 Vec4;

struct Mat4 {
    Vec4 r[4];
};

#endif
