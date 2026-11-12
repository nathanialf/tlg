/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: slot 3 of the vtable at 0x16ce490 (tlg_game_name.h): the
 * name of the entry of an index, or the class's static "<ERROR>" name (the
 * string at 0x15c04b9, interned) when the index is out of range. */
extern const char D_15c04b9[8];

// NONMATCHING: list-ilp order, two places: before __cxa_atexit the base loads the
// object's address before the destructor's (lea rsi; lea rdi), the build the other way;
// and the base loads the static's address after the null test's operand, the build before
// (`test rcx, rcx; lea rax` against `lea rax; test rcx, rcx`). Slots 3 of the other eight
// tables (0x138d500 to 0x138d920, 0x138dab0) are this shape, not written.
const Name *Object016ce490::entry(int index) const
{
    static Name D_5828ac0(D_15c04b9);
    const NamedValue *value = index >= 0 && index < count ? &values[index] : 0;
    return value ? &value->name : &D_5828ac0;
}
