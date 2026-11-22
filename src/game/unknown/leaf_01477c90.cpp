/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d68e8.h"

/* derived name: a copy of FUN_013d2490 (leaf_013d2490.cpp, where the fade's
 * update is described) over its own unit's constants (1e-5 and 1.0, as
 * there); a slot of its own classes' vtables. */
void Object016d68e8::slot5()
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
