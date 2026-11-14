/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object009690d0.h"

/* derived names: puts an object in slot `index` of the target's array of
 * exchanged references at +0x248, or the target's own object for that array
 * when none is given; nothing without a target or past the array's count. */
void FUN_00969670(Object009690d0 *self, Value009690d0 *value, int index) /* derived name */
{
    Target009690d0 *target = self->target;
    if (target && index < target->slots248.count) {
        if (value)
            target->slots248.slots[index].set(value);
        else
            target->slots248.slots[index].set(target->default60);
    }
}
