/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: the object at +0x38 of the record at +0x108 of the object
 * the pointer at 0x57c9390 holds: its state's name at +0x28, handed out by
 * value (the copy's `lock inc` before the name it is compared with is
 * made) */
struct Member057c9390_108_38 { /* derived name */

    Name state() const /* derived name */
    {
        return state28;
    }

    u8 unknown0[0x28];
    Name state28; /* +0x28 */
};

struct Member057c9390_108 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_108_38 *unknown38; /* +0x38 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x108];
    Member057c9390_108 *unknown108; /* +0x108 */
};

extern Object057c9390 *D_57c9390;
extern const char D_158acee[9]; /* "GameOver" */

/* derived names: a condition FUN_00640dc0 registers under "IsGameOver" (lea
 * at 0x641bbe, as leaf_00645980.cpp's): whether the state's name is the one
 * "GameOver" looks up (not interned: `xor ecx, ecx`); the two names
 * released before the compare's result is formed */
bool FUN_006459b0() /* derived name */
{
    return D_57c9390->unknown108->unknown38->state() == Name(D_158acee, false);
}
