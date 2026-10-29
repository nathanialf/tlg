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

/* A scalar held in every lane, as Havok's hkSimdReal is on this platform:
 * a lane broadcast, its negation the difference from zero (`vsubps` from a
 * zeroed register, not a sign flip), and a vector set from four of them
 * through two unpacks and a `movlhps` (hkMatrix3's cross-product matrix,
 * 0x1aca0). derived names. */
template <int I> inline Vec4 broadcast(const Vec4 &v)
{
    return _mm_shuffle_ps(v, v, _MM_SHUFFLE(I, I, I, I));
}

/* A float held in every lane, as hkSimdReal::fromFloat sets it on this
 * platform: the float loaded alone, then its lane shuffled to all four, so
 * a converted integer stays one scalar conversion (the curve's point at a
 * parameter, 0x7f602: `vcvtsi2ss; vpshufd`, where `_mm_set1_ps` of the
 * conversion gives `vpshufd; vcvtdq2ps`). derived name. */
inline Vec4 simdFromFloat(const float &x)
{
    const Vec4 s = _mm_load_ss(&x);
    return _mm_shuffle_ps(s, s, _MM_SHUFFLE(0, 0, 0, 0));
}

inline Vec4 negateScalar(const Vec4 &s)
{
    return _mm_sub_ps(_mm_setzero_ps(), s);
}

inline Vec4 setFromScalars(const Vec4 &a, const Vec4 &b, const Vec4 &c, const Vec4 &d)
{
    return _mm_movelh_ps(_mm_unpacklo_ps(a, b), _mm_unpacklo_ps(c, d));
}

/* hkVector4 (the reflection's name for TYPE_VECTOR4) as a class over its
 * vector: copying one is an aggregate copy, a 16-byte memcpy that the back
 * end lowers to an integer-typed load and store, so a copy is reloaded from
 * memory even right after the source was stored (the vector tolerances of
 * 0xaa340). */
struct hkVector4 {
    /* Assigned by its vector (Havok's hkVector4 declares its own
     * assignment): a struct holding vectors is assigned one vector at a
     * time, each stored before the next is read (the closest-hit
     * collector's copy of a hit, 0x696ec). */
    void operator=(const hkVector4 &v)
    {
        quad = v.quad;
    }

    Vec4 quad; /* derived name */
};

struct Mat4 {
    Vec4 r[4];
};

#endif
