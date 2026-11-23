/* src/include/tlg_game_vector00fdab40.h: the four-float vector of the walk
 * toward a target that FUN_00fdab40 and its eleven copies take (the vector
 * form of FUN_00fbcff0's walk), read from their bytes. Every name here is
 * derived. */
#ifndef TLG_GAME_VECTOR00FDAB40_H
#define TLG_GAME_VECTOR00FDAB40_H

/* derived names: four floats, 16-byte aligned, every operation a loop over
 * the four of them. A loop's reads carry the alignment of a float, so the
 * four reads a vector read is made of are one unaligned load (`vmovups`);
 * a whole vector assigned is an aligned copy (`vmovaps` stores, and the
 * `vmovaps` load of the snap to the target). Copied element by element, so
 * a vector returned by value travels through the hidden pointer and stays
 * one vector, not two halves in two registers. */
struct alignas(16) Vector4Loop { /* derived name */
    float v[4];

    Vector4Loop() {}

    Vector4Loop(const Vector4Loop &o)
    {
        for (int i = 0; i < 4; ++i)
            v[i] = o.v[i];
    }
};

inline Vector4Loop operator-(const Vector4Loop &a, const Vector4Loop &b)
{
    Vector4Loop r;
    for (int i = 0; i < 4; ++i)
        r.v[i] = a.v[i] - b.v[i];
    return r;
}

inline Vector4Loop operator+(const Vector4Loop &a, const Vector4Loop &b)
{
    Vector4Loop r;
    for (int i = 0; i < 4; ++i)
        r.v[i] = a.v[i] + b.v[i];
    return r;
}

inline Vector4Loop operator*(float s, const Vector4Loop &a)
{
    Vector4Loop r;
    for (int i = 0; i < 4; ++i)
        r.v[i] = s * a.v[i];
    return r;
}

inline Vector4Loop operator*(const Vector4Loop &a, float s)
{
    Vector4Loop r;
    for (int i = 0; i < 4; ++i)
        r.v[i] = a.v[i] * s;
    return r;
}

inline Vector4Loop operator/(const Vector4Loop &a, float s)
{
    const float inv = 1.0f / s;
    Vector4Loop r;
    for (int i = 0; i < 4; ++i)
        r.v[i] = a.v[i] * inv;
    return r;
}

inline float dot(const Vector4Loop &a, const Vector4Loop &b)
{
    float r = 0.0f;
    for (int i = 0; i < 4; ++i)
        r += a.v[i] * b.v[i];
    return r;
}

#endif
