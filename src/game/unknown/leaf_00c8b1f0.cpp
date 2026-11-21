/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: a record with a counted reference at +0x8 and an int at
 * +0x10 set when the reference is given */
struct Holder00c8b1f0 { /* derived name */
    u8 unknown0[8];
    AtomicRef0045c470<Object016b9108> unknown8; /* +0x8 */
    int unknown10;                              /* +0x10 */
};

/* derived name: the class of the value given, over the holder's (the value
 * compared first, `cmp rdi, rbx`); not traced */
class Value00c8b1f0 : public Object016b9108 /* derived name */
{
};

/* derived name: the value put into the holder's reference and the int at
 * +0x10 set, nothing done for a null holder (the value first, the holder
 * second) */
void FUN_00c8b1f0(Value00c8b1f0 *value, Holder00c8b1f0 *holder)
{
    if (holder) {
        holder->unknown8.set(value);
        holder->unknown10 = 1;
    }
}
