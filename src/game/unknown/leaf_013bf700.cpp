/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013c8500.h"

/* derived names: the walk of an upvalue (FUN_00dd0ce0, FUN_00dd1460 and FUN_00dd2120 call it by address): slot 43, then, when
 * the pointer is set and the object is walked for the first time, slots
 * 82, 4 (its mark, 0xdd0f20 in the vtable at 0x16bba90) and 121 */
void Object013c8500::visit(const Upvalue00dd2e60 *upvalue)
{
    beforeUpvalue(upvalue);
    if (upvalue && firstVisit(upvalue)) {
        enterUpvalue(upvalue);
        markUpvalue(upvalue);
        afterUpvalue(upvalue);
    }
}
