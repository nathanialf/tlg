/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_log.h"
#include "tlg_game_name.h"

/* FollowCamera (the class's name from its message "FollowCamera(%s)::Init";
 * derived names otherwise), its vtable at 0x16abf70 (config/
 * vtables.derived.base.txt, stored by FUN_0061c160, whose body inlines this
 * function, and FUN_0061c330). Slot 5 of the vtable (its pointer at
 * 0x16abfa8), written as a free function as FixCamera's (leaf_0061ae60.cpp):
 * calls FUN_00afded0 with 1 and 2, sets the three floats at +0xa0 (3, 0.5,
 * 180) and clears the two ints at +0xac (stored as one qword; as floats the
 * five stores are vectorised, as the base does not), then logs the Init
 * message with the name's string through the variadic FUN_00c831d0, a tail
 * call (its first
 * argument is not read, so rdi is left unset). The name at +0xc is the base's
 * (FixCamera's file). */
struct FollowCamera {
    u8 unknown0[0xc];
    Name unknownC; /* +0xc */
    u8 unknown10[0xa0 - 0x10];
    float unknownA0;
    float unknownA4;
    float unknownA8;
    int unknownAC;
    int unknownB0;
};

extern const char D_1589864[]; /* "FollowCamera(%s)::Init\n" */

void FUN_00afded0(FollowCamera *self, int unknown, int kind); /* derived name */

void FUN_0061c420(FollowCamera *self) /* derived name */
{
    FUN_00afded0(self, 1, 2);
    self->unknownA0 = 3.0f;
    self->unknownA4 = 0.5f;
    self->unknownA8 = 180.0f;
    self->unknownAC = 0;
    self->unknownB0 = 0;
    FUN_00c831d0(self, D_1589864, D_17ac870[self->unknownC.index].string0);
}
