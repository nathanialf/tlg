/* Math value types with user-provided copy constructors: a Float4 returned
 * by value travels through a hidden pointer, as the executable shows at
 * FUN_004ba630. Four-byte aligned, unlike the 16-byte Vec4 rows of
 * tlg_simd.h. derived names. */
#ifndef TLG_MATH_H
#define TLG_MATH_H

struct Float4 {
    float x;
    float y;
    float z;
    float w;

    Float4() {}

    Float4(const Float4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
};

#endif
