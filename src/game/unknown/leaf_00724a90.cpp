/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ac7c8.h"

/* derived names: slot 10 of the vtable at 0x16ac7c8: the array emptied (its
 * block given back) and the object at +0xb38 appended; the array's count
 * returned. */
unsigned Object016ac7c8::FUN_00724a90(Array05943280<Object016b9108 *> &objects) const
{
    objects.clear();
    objects.push(object());
    return objects.size();
}
