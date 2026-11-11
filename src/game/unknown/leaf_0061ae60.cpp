/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* FixCamera (the class's name from its messages "FixCamera(%s)::Init" and
 * "FixCamera(%s)::Term"; derived names otherwise): slot 5 of its vtable at
 * 0x16abef8 (its pointer at 0x16abf30; stored by FUN_0061ab50 and the
 * destructors FUN_0061adc0 and FUN_0061ae10, the vtable without a row),
 * written as a free function: calls FUN_00afded0 with 26 and 2, then logs the
 * Init message with the string of the name at +0xc through the variadic
 * FUN_00c831d0 (leaf_00b34430.cpp's), a tail call. Called also directly by
 * FUN_0061ab50. */
struct FixCamera {
    u8 unknown0[0xc];
    Name unknownC; /* +0xc */
};

extern const char D_158984f[]; /* "FixCamera(%s)::Init\n" */

void FUN_00afded0(FixCamera *self, int unknown, int kind);   /* derived name */
void FUN_00c831d0(FixCamera *self, const char *format, ...); /* derived name */

// NONMATCHING: the base does not set rdi for FUN_00c831d0 (its first argument undefined
// after the call to FUN_00afded0): a dead argument replaced by undef at the call
// site, as DeadArgElim does for a local-linkage callee only (the internal-
// linkage lead of tlg_game_name.h's accessors and their dropped returns).
void FUN_0061ae60(FixCamera *self) /* derived name */
{
    FUN_00afded0(self, 26, 2);
    FUN_00c831d0(self, D_158984f, D_17ac870[self->unknownC.index].string0);
}
