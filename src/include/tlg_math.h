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

    /* constant: the engine's points below are initialised at compile time
     * (no initializer runs for them) */
    constexpr Float4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}

    Float4(const Float4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
};

/* derived names: three points (w 1): the lowest and the highest a box can
 * hold and the origin, defined once with constant initialisers
 * (float4_points.cpp). A unit that copies one sees only this declaration:
 * Float4's copy is four loads and four stores, which the unit's own
 * optimiser turns into integer moves, and the link folds the values in: the
 * constant-pool vectors of FUN_007ae5c0's family, built as integers
 * (`vmovaps` of 0x1536f60, 0x1536f70, 0x1536f80 stored at +0x50 to +0x70). */
extern const Float4 FLOAT4_POINT_MIN;    /* derived name */
extern const Float4 FLOAT4_POINT_MAX;    /* derived name */
extern const Float4 FLOAT4_POINT_ORIGIN; /* derived name */

/* derived names: ones, defined the same way: copied at +0x6c and +0x7c by
 * FUN_005a8340 and FUN_00d10e60 (the four a 16-byte integer vector of
 * 0x3f800000, the float an integer store of it, neither merged with the
 * float stores around them) */
extern const Float4 FLOAT4_ONE; /* derived name */
extern const float FLOAT_ONE;   /* derived name */

/* Float4 with 16-byte alignment: returned by value through the hidden
 * pointer, its copy moved with aligned vector moves (FUN_013d01e0 and its
 * three siblings, slots 1 to 4 of the vtable at 0x16d3798); set by its four
 * floats, which the stores merge into vector stores (FUN_00e903a0). */
struct alignas(16) Float4A { /* derived name */
    float x;
    float y;
    float z;
    float w;

    Float4A() {}

    constexpr Float4A(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}

    Float4A(const Float4A &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}

    void set(float x_, float y_, float z_, float w_)
    {
        x = x_;
        y = y_;
        z = z_;
        w = w_;
    }
};

/* derived names: the x axis, defined with the points (float4_points.cpp):
 * assigned at +0x90 and +0xb4 by FUN_00e90cb0 and FUN_00e91f20 (`mov edx,
 * 0x3f800000; vmovd xmm0, edx`: the value reaches the link as integers) */
extern const Float4A FLOAT4A_X; /* derived name */
extern const Float4 FLOAT4_X;   /* derived name */

#endif
