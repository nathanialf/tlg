/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013c8500.h"

/* derived names: the walk of a C function (kind 10 of a value; FUN_00dd1d60
 * and FUN_00dd2170 call it by address): slot 48, then, when the pointer is
 * set and the function is walked for the first time, slots 87, 8 (its mark,
 * FUN_00dd13d0) and 126 */
void Object013c8500::visit(const Record00dd13d0 *function)
{
    beforeCFunction(function);
    if (function && firstVisit(function)) {
        enterCFunction(function);
        visit00dd13d0(function);
        afterCFunction(function);
    }
}
