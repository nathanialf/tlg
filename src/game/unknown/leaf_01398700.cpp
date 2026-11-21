/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01398700.h"

/* derived names: calls FUN_00b41780 with the object and the pointer at +0xa0,
 * as a tail call; slot 56 of the vtable at 0x16cfb98 (its pointer at
 * 0x16cfd68), the vtable stored by FUN_00b40f10. FUN_00b41780 tests the
 * pointer for null and copies its settings (leaf_00b41780.cpp). Class and
 * method unknown. */
void FUN_00b41780(Object01398700 *self, Target01398700 *value); /* derived name */

void FUN_01398700(Object01398700 *self) /* derived name */
{
    FUN_00b41780(self, self->unknowna0);
}
