/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hk_reflect.h"

/* derived names: slot 6 of the vtable at 0x16c9fe8 (its pointer at
 * 0x16ca028, after 0xeb2890's count): the three corners of triangle i
 * (20-byte entries at +0x20, three 16-bit vertex indices at +0x0, +0x2,
 * +0x4) read from the vertices at +0x18 (three floats each) into the three
 * vectors given, last corner first, each loaded as three floats and then
 * its w cleared. The class is not traced. */
struct Triangle00eb28a0 { /* derived name */
    u16 a;
    u16 b;
    u16 c;
    u8 unknown6[0xe];
};

struct Object00eb28a0 { /* derived name */
    u8 unknown0[0x18];
    const float (*vertices)[3];
    const Triangle00eb28a0 *triangles;
};

/* Three floats in memory as a vector, x and y read as one eight-byte double
 * and z alone (the w lane left as the loads give it), as loadXYZ_0 before
 * its blend. derived name. */
static inline Vec4 loadXYZ00eb28a0(const float *p) /* derived name */
{
    return _mm_movelh_ps(_mm_castpd_ps(_mm_load_sd(reinterpret_cast<const double *>(p))),
                         _mm_load_ss(p + 2));
}

// NONMATCHING: register assignment from the first instruction (the triangle pointer in r9, the base's r8; 19 of 31 equal); equal with r248784's demanded-elements change for bitcasts (the probe -tlg-bitcast-demanded at both stages, round 387D): loadXYZ_0's zero upper lane, as leaf_00ea0b80.cpp
void FUN_00eb28a0(const Object00eb28a0 *self, int i, Vec4 *corners) /* derived name */
{
    const Triangle00eb28a0 &triangle = self->triangles[i];
    corners[0] = loadXYZ00eb28a0(self->vertices[triangle.c]);
    corners[1] = loadXYZ00eb28a0(self->vertices[triangle.b]);
    corners[2] = loadXYZ00eb28a0(self->vertices[triangle.a]);
    corners[0] = _mm_blend_ps(corners[0], _mm_setzero_ps(), 8);
    corners[1] = _mm_blend_ps(corners[1], _mm_setzero_ps(), 8);
    corners[2] = _mm_blend_ps(corners[2], _mm_setzero_ps(), 8);
}
