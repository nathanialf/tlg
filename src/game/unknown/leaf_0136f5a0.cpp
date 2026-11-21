/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0136f730.h"

/* derived names: slot 9 of the vtable at 0x16cbf30 (its pointer at
 * 0x16cbf88): each of the four pairs of its argument whose second reference
 * is set is handed to FUN_008113a0 with the pointer at +0x28, then both
 * references are emptied, the first one first. The object itself is not
 * used. */
void FUN_0136f5a0(void *, Object0136f730 *object) /* derived name */
{
    for (int i = 0; i < 4; i++) {
        if (object->second78[i].get()) {
            FUN_008113a0(object->unknown28, object->first58[i].get(), object->second78[i].get());
            object->first58[i].clear();
            object->second78[i].clear();
        }
    }
}
