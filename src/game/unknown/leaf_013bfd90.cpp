/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013c8500.h"

/* derived names: the walk of a method (FUN_00dd1460 and FUN_00dd1e40 call it by address): slot 50, then, when
 * the pointer is set and the object is walked for the first time, slots
 * 89, 10 (its mark, 0xdd1510) and 128 */
void Object013c8500::visit(const Record00dd1510 *method)
{
    beforeMethod(method);
    if (method && firstVisit(method)) {
        enterMethod(method);
        visit00dd1510(method);
        afterMethod(method);
    }
}
