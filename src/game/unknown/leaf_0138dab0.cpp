/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: slot 3 of the vtable at 0x16ce6d0 (tlg_game_name.h): the
 * name of the entry of an index, or the class's static "<ERROR>" name (the
 * string at 0x15c04b9, interned) when the index is out of range, as
 * FUN_0138d450 is for 0x16ce490. */
extern const char D_15c04b9[8];

/* The static's guard is at 0x5828ae8 in the base (0x8 above the object). */
const Name *Object016ce6d0::entry(int index) const
{
    static Name D_5828ae0(D_15c04b9);
    const NamedValue *value = index >= 0 && index < count ? &values[index] : 0;
    return value ? &value->name : &D_5828ae0;
}
