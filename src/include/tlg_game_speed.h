/* src/include/tlg_game_speed.h: the game's four speeds, kept between 0 and
 * 1 in the record the pointer at 0x57c9390 holds, and the speed they make
 * (game region; docs/TARGETS.md). Every name here is derived. FUN_001b0680
 * (the script's TricoGame_SetGameSpeed) sets the first or the third,
 * FUN_00596a00 the fourth. */
#ifndef TLG_GAME_SPEED_H
#define TLG_GAME_SPEED_H

#include "tlg_types.h"

/* derived name: a value kept between two bounds, by reference to one of
 * the three (each bound a temporary whose address the select takes; both
 * tests on the value: `v < 1` then `v >= 0`) */
template <class T> inline const T &clampTo(const T &value, const T &low, const T &high)
{
    return value < low ? low : value < high ? value : high;
}

/* derived names: the object whose speed at +0x1b8 the four make; the rest
 * is not traced */
struct Object05938c40 { /* derived name */
    u8 unknown0[0x1b8];
    float speed; /* +0x1b8 */
};

extern Object05938c40 *D_5938c40;

/* derived names: the four speeds of the game's record; the rest is not
 * traced */
struct Game057c9390 { /* derived name */
    u8 unknown0[0x140];
    float speeds[4]; /* +0x140 */

    /* derived name: one of the four speeds set, kept between 0 and 1, and
     * the game's speed made again (the record's pointer read once: the
     * speed just set is not read again) */
    void setSpeed(int slot, float speed)
    {
        speeds[slot] = clampTo(speed, 0.0f, 1.0f);
        updateSpeed();
    }

    /* derived name: the game's speed, the first of the four that is not 1 */
    void updateSpeed() const
    {
        for (int i = 0; i < 4; ++i) {
            if (speeds[i] != 1.0f) {
                D_5938c40->speed = speeds[i];
                return;
            }
        }
        D_5938c40->speed = 1.0f;
    }
};

extern Game057c9390 *D_57c9390;

#endif
