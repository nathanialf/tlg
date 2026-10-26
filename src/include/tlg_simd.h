/* SIMD types shared by the rebuilt sources. The engine's math stores rows as
 * 16-byte-aligned vectors of four floats and moves them with aligned SSE
 * loads and stores. */
#ifndef TLG_SIMD_H
#define TLG_SIMD_H

#include <xmmintrin.h>

typedef __m128 Vec4;

/* One lane of a vector in memory as a float, read and written in place, as
 * Havok's hkVector4 operator() gives it (a single `vmovss`, not a vector
 * shuffle). derived name. */
inline float &lane(Vec4 &v, int i)
{
    return reinterpret_cast<float *>(&v)[i];
}

inline const float &lane(const Vec4 &v, int i)
{
    return reinterpret_cast<const float *>(&v)[i];
}

/* hkVector4 (the reflection's name for TYPE_VECTOR4) as a class over its
 * vector: copying one is an aggregate copy, a 16-byte memcpy that the back
 * end lowers to an integer-typed load and store, so a copy is reloaded from
 * memory even right after the source was stored (the vector tolerances of
 * 0xaa340). */
struct hkVector4 {
    Vec4 quad; /* derived name */
};

struct Mat4 {
    Vec4 r[4];
};

#endif
