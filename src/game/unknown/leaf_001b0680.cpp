/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_hks.h"

/* derived names: the script C function "TricoGame_SetGameSpeed"
 * (FUN_001bd010 registers it): sets one of the four game speeds at +0x140
 * of the game's record to its first argument's number, kept between 0 and
 * 1; the speed is the third ("TailSupport", the function's static name at
 * 0x57c9130, looked up without interning it) when the second argument names
 * it, else the first. The speed at +0x1b8 of the object D_5938c40 points to
 * becomes the first of the four that is not 1, or 1. Returns 0. */
struct Game057c9390 { /* derived name */
    u8 unknown0[0x140];
    float speeds[4]; /* +0x140 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x1b8];
    float speed; /* +0x1b8 */
};

extern Game057c9390 *D_57c9390;
extern Object05938c40 *D_5938c40;

/* derived name: a value kept between two bounds, by reference to one of
 * the three (each bound a temporary whose address the select takes; both
 * tests on the value: `v < 1` then `v >= 0`) */
template <class T> static inline const T &clampTo(const T &value, const T &low, const T &high)
{
    return value < low ? low : value < high ? value : high;
}

/* derived name: the game's speed, the first of the four that is not 1 */
static inline void updateGameSpeed()
{
    for (int i = 0; i < 4; ++i) {
        if (D_57c9390->speeds[i] != 1.0f) {
            D_5938c40->speed = D_57c9390->speeds[i];
            return;
        }
    }
    D_5938c40->speed = 1.0f;
}

/* derived name: one of the four speeds set, kept between 0 and 1, and the
 * game's speed made again */
static inline void setGameSpeed(int slot, float speed)
{
    D_57c9390->speeds[slot] = clampTo(speed, 0.0f, 1.0f);
    updateGameSpeed();
}

// NONMATCHING: the slot: the base keeps the static name's index (r14d) and compares it with
// the argument's after the argument's name is released (`mov eax, 2; cmp ebx, r14d; je; xor
// eax, eax`), the build holds the slot in r12 from before the name is read (one more
// callee-saved register, the frame 8 bytes deeper). The speed's copy at the clamp, the clamp's
// two tests on the value and the four tests with their two stores are the base's; written
// without setGameSpeed the slot is the base's and the clamp takes the speed's own slot
int FUN_001b0680(lua_State *state) /* derived name */
{
    const int count = argumentCount(state);
    const float speed = toNumber(state, 1);
    int slot = 0;
    if (count >= 2) {
        const Name kind = nameArgument(state, 2);
        static Name D_57c9130("TailSupport", false);
        if (kind == D_57c9130)
            slot = 2;
    }
    setGameSpeed(slot, speed);
    return 0;
}
