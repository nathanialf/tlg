/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_fade013d2490.h"

/* derived name: one update of a fading object (tlg_game_fade013d2490.h;
 * one of ten byte-identical copies, each a slot of its own classes'
 * vtables): the entries' ints cleared, then the level moved by the clock's
 * step over the fade's length; a fade-in shorter than 1e-5 or a level that
 * reaches 1 ends in state 2, a fade-out whose level is no longer above 0 in
 * state 0 */
// NONMATCHING: 41/52, the blocks are the base's; first difference a register exchange (the
// loop's two offsets: the base keeps 0x40 in esi and 0x90 in edx and sets edx first), then two
// instructions in the other order (the base stores the level before `vucomiss xmm0, xmm1` in
// state 3). The nine copies (0x13d6090, 0x13d8910, 0x13dbe70, 0x13e15f0, 0x13ecff0, 0x13eec60,
// 0x13f2ff0, 0x13f95a0, 0x1477c90) are not written.
void FUN_013d2490(Fade013d2490 *self) /* derived name */
{
    FadeTarget013d2490 *target = self->owner->target;
    for (int i = 0; i < target->count; ++i) {
        self->entries[i].unknown40 = 0;
        target->entries[i].unknown90 = 0;
    }
    self->unknown6c = 0;
    if (self->state == 1) {
        if (self->fadeIn < 0.00001f ||
            (self->level += self->owner->clock->step / self->fadeIn) >= 1.0f) {
            self->state = 2;
            self->level = 1.0f;
        }
    } else if (self->state == 3) {
        self->level -= self->owner->clock->step / self->fadeOut;
        if (!(self->level > 0.0f)) {
            self->state = 0;
            self->level = 0.0f;
        }
    }
}
