/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013c8500.h"

/* derived names: the walk of a closure (kind 9 of a value; FUN_00dd1d60 and
 * FUN_00dd2160 call it by address): slot 49, then, when the pointer is set
 * and the closure is walked for the first time, slots 88, 9 (its mark,
 * FUN_00dd1460) and 127 */
void Object013c8500::visit(const Record00dd1460 *closure)
{
    beforeClosure(closure);
    if (closure && firstVisit(closure)) {
        enterClosure(closure);
        visit00dd1460(closure);
        afterClosure(closure);
    }
}
