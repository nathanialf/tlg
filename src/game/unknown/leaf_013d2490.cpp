/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d3908.h"

/* derived name: one update of a fading object (tlg_game_fade013d2490.h;
 * one of fourteen byte-identical copies, each a slot of its own classes'
 * vtables): the entries' ints cleared, then the level moved by the clock's
 * step over the fade's length; a fade-in shorter than 1e-5 or a level that
 * reaches 1 ends in state 2, a fade-out whose level is no longer above 0 in
 * state 0. The two state-2 arms are written apart: the Control Flow
 * Optimizer merges their tails, and the merged block then ends in its own
 * `ret` (one arm written with `||` falls into the shared return). */
void Object016d3908::slot5()
{
    FadeTarget013d2490 *target = owner->target;
    for (int i = 0; i < target->count; ++i) {
        entries.at(i).unknown40 = 0;
        target->entries[i].unknown90 = 0;
    }
    unknown6c = 0;
    if (state == 1) {
        if (fadeIn < 0.00001f) {
            state = 2;
            level = 1.0f;
        } else {
            level += owner->clock->step / fadeIn;
            if (level >= 1.0f) {
                state = 2;
                level = 1.0f;
            }
        }
    } else if (state == 3) {
        level -= owner->clock->step / fadeOut;
        if (!(level > 0.0f)) {
            state = 0;
            level = 0.0f;
        }
    }
}
