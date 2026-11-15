/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: slot 3 of the vtable at 0x16ce490 (tlg_game_name.h): the
 * name of the entry of an index, or the class's static "<ERROR>" name (the
 * string at 0x15c04b9, interned) when the index is out of range. */
extern const char D_15c04b9[8];

// NONMATCHING: the instructions are the base's; the static's guard is 0x68 above the object in
// the base (0x5828b28 for 0x5828ac0), the module puts it 8 bytes below, and the layout refuses
// the row. Slots 3 of the other eight tables (0x138d500 to 0x138d920, 0x138dab0) are this shape,
// not written.
const Name *Object016ce490::entry(int index) const
{
    static Name D_5828ac0(D_15c04b9);
    const NamedValue *value = index >= 0 && index < count ? &values[index] : 0;
    return value ? &value->name : &D_5828ac0;
}
