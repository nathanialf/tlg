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

/* One lane of a vector taken from the whole vector, as Havok's
 * hkVector4::getComponent<I>() gives it: the vector is read and the lane
 * extracted, which the back end narrows to a scalar load at the lane's
 * offset, but only after the loop strength reduction has based a loop's
 * address on the vector (0x2b620's `add rdi, 0x50` with the lane at
 * `[rdi+0xc]`, where lane() gives `add rdi, 0x5c`). derived name. */
template <int I> inline float component(const Vec4 &v)
{
    return v[I];
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
