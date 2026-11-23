/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_speed.h"
#include "tlg_hks.h"

/* derived names: the script C function "TricoGame_SetGameSpeed"
 * (FUN_001bd010 registers it): sets one of the four game speeds at +0x140
 * of the game's record to its first argument's number, kept between 0 and
 * 1; the speed is the third ("TailSupport", the function's static name at
 * 0x57c9130, looked up without interning it) when the second argument names
 * it, else the first. The speed at +0x1b8 of the object D_5938c40 points to
 * becomes the first of the four that is not 1, or 1. Returns 0. */
/* derived name: the name of the third speed, "TailSupport", made on first
 * use without interning it (the static at 0x57c9130) */
static inline const Name &tailSupportName()
{
    static Name D_57c9130("TailSupport", false);
    return D_57c9130;
}

/* The name's comparison is its own statement under the count's test: the
 * argument's temporary name is released before the branch, so the index
 * of the static is read before the release and compared after it (`cmp
 * ebx, r14d` at 0x1b07ac); under `count >= 2 &&` the comparison is a phi
 * of the condition and is made before the release. */
int FUN_001b0680(lua_State *state) /* derived name */
{
    const int count = argumentCount(state);
    const float speed = toNumber(state, 1);
    int slot = 0;
    if (count >= 2) {
        if (nameArgument(state, 2) == tailSupportName())
            slot = 2;
    }
    D_57c9390->setSpeed(slot, speed);
    return 0;
}
