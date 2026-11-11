/* src/include/tlg_game_vector.h: the game's four-lane vector and the
 * constants its header gives every file that includes it (game region;
 * docs/TARGETS.md). Every name here is derived: the executable is stripped
 * and no string names them.
 *
 * Each of the 325 game files whose static initializer begins with the same
 * nineteen 16-byte stores (0x2030d0 to 0x1323040 in the constructor table
 * at 0x57adf80) holds its own copy of these objects, in its own .bss: they
 * are namespace-scope `static const` objects of a class whose constructor is
 * not constexpr, so every unit runs the constructors into its copies before
 * its own globals. Where a unit's copy lies is a fact about that unit, not
 * about the header: config/header_statics.base.txt gives it per unit, and
 * the gate checks it against the unit's own code (tools/match_check.py,
 * "header statics"). */
#ifndef TLG_GAME_VECTOR_H
#define TLG_GAME_VECTOR_H

#include "tlg_simd.h"

/* derived name: four floats in one 16-byte register, set lane by lane from
 * floats, or from four integers for a lane mask (the x mask is built as an
 * integer, `mov eax, -1; vmovd`, where the x axis is a float, `vmovss` of
 * 1.0f from the pool) */
class Vector4 /* derived name */
{
  public:
    Vector4(float x, float y, float z, float w) : v(_mm_setr_ps(x, y, z, w)) {}

    Vector4(unsigned x, unsigned y, unsigned z, unsigned w)
        : v(_mm_castsi128_ps(_mm_setr_epi32(x, y, z, w)))
    {
    }

    Vec4 v;
};

/* derived names: the constants in the order every initializer builds them.
 * The squared epsilon is the product of the epsilon with itself (0x2edbe6fe,
 * one ulp under the float nearest 1e-10). */
static const float VECTOR_EPSILON_VALUE = 1e-5f; /* derived name */
static const float VECTOR_EPSILON_SQ_VALUE =
    VECTOR_EPSILON_VALUE * VECTOR_EPSILON_VALUE; /* derived name */

static const Vector4 VECTOR_ZERO(0.0f, 0.0f, 0.0f, 0.0f);                       /* derived name */
static const Vector4 VECTOR_ONE(1.0f, 1.0f, 1.0f, 1.0f);                        /* derived name */
static const Vector4 VECTOR_MINUS_ONE(-1.0f, -1.0f, -1.0f, -1.0f);              /* derived name */
static const Vector4 VECTOR_HALF(0.5f, 0.5f, 0.5f, 0.5f);                       /* derived name */
static const Vector4 VECTOR_EPSILON(VECTOR_EPSILON_VALUE, VECTOR_EPSILON_VALUE, /* derived name */
                                    VECTOR_EPSILON_VALUE, VECTOR_EPSILON_VALUE);
static const Vector4 VECTOR_EPSILON_SQ(VECTOR_EPSILON_SQ_VALUE,
                                       VECTOR_EPSILON_SQ_VALUE, /* derived name */
                                       VECTOR_EPSILON_SQ_VALUE, VECTOR_EPSILON_SQ_VALUE);
static const Vector4 VECTOR_TINY(1e-9f, 1e-9f, 1e-9f, 1e-9f); /* derived name */
static const Vector4 VECTOR_PI(3.14159265f, 3.14159265f, 3.14159265f,
                               3.14159265f);           /* derived name */
static const Vector4 VECTOR_X(1.0f, 0.0f, 0.0f, 0.0f); /* derived name */
static const Vector4 VECTOR_Y(0.0f, 1.0f, 0.0f, 0.0f); /* derived name */
static const Vector4 VECTOR_Z(0.0f, 0.0f, 1.0f, 0.0f); /* derived name */
static const Vector4 VECTOR_W(0.0f, 0.0f, 0.0f, 1.0f); /* derived name */
static const Vector4 VECTOR_MASK_W(0u, 0u, 0u, ~0u);   /* derived name */
static const Vector4 VECTOR_MASK_Z(0u, 0u, ~0u, 0u);   /* derived name */
static const Vector4 VECTOR_MASK_Y(0u, ~0u, 0u, 0u);   /* derived name */
static const Vector4 VECTOR_MASK_X(~0u, 0u, 0u, 0u);   /* derived name */
static const Vector4 VECTOR_MASK_XY(~0u, ~0u, 0u, 0u); /* derived name */
static const Vector4 VECTOR_MASK_XZ(~0u, 0u, ~0u, 0u); /* derived name */
static const Vector4 VECTOR_MASK_XW(~0u, 0u, 0u, ~0u); /* derived name */

#endif
