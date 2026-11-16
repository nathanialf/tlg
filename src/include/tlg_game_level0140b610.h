/* src/include/tlg_game_level0140b610.h: a level between 0 and 1 stepped by
 * a clock, as FUN_0140b610 and its copy FUN_01490450 read it (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_LEVEL0140B610_H
#define TLG_GAME_LEVEL0140B610_H

#include "tlg_types.h"

/* derived names: a level between 0 and 1 moved towards one end by the
 * clock's step over its length, the direction set by each call */
struct Clock0140b610 { /* derived name */
    u8 unknown0[0x14];
    float step; /* +0x14 */
};

struct Owner0140b610 { /* derived name */
    u8 unknown0[0x10];
    Clock0140b610 *clock; /* +0x10 */
};

struct Level0140b610 { /* derived name */
    u8 unknown0[0x8];
    Owner0140b610 *owner; /* +0x8 */
    int rising;           /* +0x10: 1 towards 1, 0 towards 0 */
    int started;          /* +0x14: set when it starts rising from rest */
    float level;          /* +0x18 */
    float length;         /* +0x1c */
};

/* derived name: the smaller of two values, by value */
template <typename T> inline T minimum(T a, T b)
{
    return a < b ? a : b;
}

#endif
