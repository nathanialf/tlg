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

    Float4A(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}

    Float4A(const Float4A &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}

    void set(float x_, float y_, float z_, float w_)
    {
        x = x_;
        y = y_;
        z = z_;
        w = w_;
    }
};

#endif
