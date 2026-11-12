/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a step of a state machine (its address at 0x16b7fe8 in a
 * vtable; the functions at 0xa84ba0 and 0xa84d60 jump to it): FUN_0138e140
 * finds the second argument's slot (its pointers at +0x30 and +0x18 and the
 * first argument's key at +0xc); in state 0 the slot becomes state 3 when
 * the first argument's int at +0x28 is 0 and state 1 otherwise; from state 1
 * FUN_00c1b410 runs, the slot takes the state the first argument's table at
 * +0x34 gives for its state, and FUN_00c1b520 runs. Other states do nothing.
 * The classes are not traced. */
struct Slot00c19e60 { /* derived name */
    u8 unknown0[0x24];
    int state; /* +0x24 */
};

struct Machine00c19e60 { /* derived name */
    u8 unknown0[0xc];
    u8 key[0x1c];  /* +0xc */
    int unknown28; /* +0x28 */
    u8 unknown2c[8];
    int next[1]; /* +0x34: the state after each state; its extent not traced */
};

struct Holder00c19e60 { /* derived name */
    u8 unknown0[0x18];
    void *unknown18; /* +0x18 */
    u8 unknown20[0x10];
    void *unknown30; /* +0x30 */
};

Slot00c19e60 *FUN_0138e140(void *table, void *owner, const void *key); /* derived name */
void FUN_00c1b410(Holder00c19e60 *holder, Machine00c19e60 *machine,
                  Slot00c19e60 *slot); /* derived name */
void FUN_00c1b520(Holder00c19e60 *holder, Machine00c19e60 *machine,
                  Slot00c19e60 *slot); /* derived name */

void FUN_00c19e60(Machine00c19e60 *machine, Holder00c19e60 *holder) /* derived name */
{
    if (!holder->unknown30)
        return;
    Slot00c19e60 *slot = FUN_0138e140(holder->unknown30, holder->unknown18, machine->key);
    if (!slot)
        return;
    if (slot->state != 1) {
        if (slot->state != 0)
            return;
        if (machine->unknown28 == 0) {
            slot->state = 3;
            return;
        }
        slot->state = 1;
    }
    FUN_00c1b410(holder, machine, slot);
    slot->state = machine->next[slot->state];
    FUN_00c1b520(holder, machine, slot);
}
