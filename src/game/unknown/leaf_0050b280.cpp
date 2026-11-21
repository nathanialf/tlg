/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object0042dbe0.h"

/* derived names: slot 18 of the vtable at 0x16aad98 (stored by its
 * constructor; slot 18 of the base is FUN_0042dbe0): FUN_0042dbe0's body,
 * then, with the slot at +0x108 filled, an animation running (+0x134) and
 * its name at +0x110, a line of debug text "Anim: %s" with the name drawn
 * half a unit above the position at +0x50 */
// NONMATCHING: --module 18/61, 218 bytes as the base: the base takes the slot's address once
// (`lea r14, [rbx+0x108]`, then `cmp qword [r14], 0` and the re-test after the body), the build
// folds it into each load (`cmp qword [rbx+0x108], 0`; CodeGenPrepare's address sinking); in
// this file with FUN_0042dbe0 (one unit) the re-test is threaded away and the body 8 bytes short
void FUN_0050b280(Object0042dbe0 *self) /* derived name */
{
    FUN_0042dbe0(self);
    if (self->unknown108 && self->unknown134 && self->animation.index) {
        Position0042dbe0 position = self->position;
        position.y += 0.5f;
        TextStyle0042dbe0 style = {0xc080a0ff, 1.0f};
        FUN_00205720(&position, &style, 0, "Anim: %s", D_17ac870[self->animation.index].string0);
    }
}
