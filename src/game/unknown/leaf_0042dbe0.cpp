/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0042dbe0.h"

/* derived names: a virtual method (its address at 0x16a8218 and 0x16a9a30 in
 * .data.rel.ro) that, when the pointer at +0x28 is set and the one at +0x108
 * is still null, has FUN_002054d0 fill the slot at +0x108 from it (third
 * argument 0) and then clears bit 1 of the byte at +0x100 of the object the
 * slot now holds. FUN_002054d0 takes the slot by address and exchanges the
 * pointer into it. Class and method unknown; the fields' types beyond their
 * widths are not traced. */
void FUN_0042dbe0(Object0042dbe0 *self) /* derived name */
{
    if (self->unknown28 && !self->unknown108) {
        FUN_002054d0(&self->unknown108, self->unknown28, 0);
        if (self->unknown108)
            self->unknown108->flags100 &= ~2;
    }
}

/* derived names: the method in the same place of another class (its address
 * at 0x16aa780): FUN_0042dbe0's body, then, with the slot at +0x108 filled,
 * a line of debug text "JumpSpeed: %f" with the float at +0x1dc drawn half a
 * unit above the position at +0x50 (FUN_00205720: the position, a colour
 * 0xc080a0ff and a scale of 1, a flag 0, the format and its value) */
// NONMATCHING: 195 bytes as the base, the order of the copy's stores only: the base stores x, the
// style, y, then z and w (0x4eb059, 0x4eb05c), this build z and w before the style and y. The
// copy is field by field in the base (every field read first, z and w not merged into one 8-byte
// store); a 16-byte copy gives one vector move, a raised field in the constructor merges z and w
// (DAGCombiner's walk up the chain stops at the float store of y). Round 589E
void FUN_004eafd0(Object0042dbe0 *self) /* derived name */
{
    FUN_0042dbe0(self);
    if (self->unknown108) {
        const Position0042dbe0 &at = self->position;
        Position0042dbe0 position(at.x, at.y, at.z, at.w);
        position.y += 0.5f;
        TextStyle0042dbe0 style(0xc080a0ff, 1.0f);
        FUN_00205720(position, style, 0, "JumpSpeed: %f", self->jumpSpeed);
    }
}
