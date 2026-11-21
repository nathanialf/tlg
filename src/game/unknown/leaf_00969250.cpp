/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_array.h"

/* derived names: the object at +0x10 of FUN_00969250's owner: an array of
 * counted references at +0x200 */
struct Slots00969250 { /* derived name */
    u8 unknown0[0x200];
    Array05943280<AtomicRef0045c470<Object016b9108>> slots; /* +0x200 */
};

/* derived name: the class of the value given, over the slots' (the value
 * compared first, `cmp rsi, rbx`); not traced */
class Value00969250 : public Object016b9108 /* derived name */
{
};

struct Owner00969250 { /* derived name */
    u8 unknown0[0x10];
    Slots00969250 *slots10; /* +0x10 */
};

/* derived name: the reference at `index` replaced by `value` where the
 * owner has its slots and the index is below their count (compared
 * unsigned, `cmp [rax+0x208], edx; jbe`, the element at the signed index);
 * called from 0x96a00a and two more sites */
void FUN_00969250(Owner00969250 *owner, Value00969250 *value, int index)
{
    Slots00969250 *slots = owner->slots10;
    if (slots && unsigned(index) < slots->slots.size())
        slots->slots.at(index).set(value);
}
