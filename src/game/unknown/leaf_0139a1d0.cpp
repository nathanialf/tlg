/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01398700.h"

/* derived names: slot 10 of the vtable at 0x16cfb98 (its pointer at
 * 0x16cfbf8), the vtable stored by FUN_00b40f10: when the simulation at +0xa0
 * has its part at +0x80, copies the simulation's settings
 * (FUN_00b41780, leaf_00b41780.cpp) and then the part's nine words to +0x118.
 * Class and method unknown. */
void FUN_00b41780(Object01398700 *self, Target01398700 *simulation); /* derived name */

void FUN_0139a1d0(Object01398700 *self) /* derived name */
{
    Target01398700 *simulation = self->unknowna0;
    if (!simulation || !simulation->unknown80)
        return;
    FUN_00b41780(self, simulation);
    const Values01398700 *values = simulation->unknown80;
    self->unknown118 = *values;
}
