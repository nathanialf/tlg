/* src/include/tlg_game_float2.h: a pair of floats and the constant its
 * header gives the files that include it (game region; docs/TARGETS.md).
 * Every name here is derived: the executable is stripped and no string names
 * them.
 *
 * Three static initializers (0x2030d0, 0xa63b80, 0xb654e0) build the same
 * pair into their own units' .bss, 0xb654e0 before its vector constants and
 * the four pairs of tlg_game_cell.h after them: a namespace-scope
 * `static const` object of a class whose constructor is not constexpr, as
 * the vector constants of tlg_game_vector.h are. Where a unit's copy lies is a fact
 * about the unit: config/header_statics.base.txt. */
#ifndef TLG_GAME_FLOAT2_H
#define TLG_GAME_FLOAT2_H

struct Float2 /* derived name */
{
    Float2(float x, float y) : x(x), y(y) {}

    float x; /* +0x0 */
    float y; /* +0x4 */
};

/* derived name: a 960 by 540 extent (half of 1920 by 1080) */
static const Float2 LAYOUT_EXTENT(960.0f, 540.0f); /* derived name */

#endif
