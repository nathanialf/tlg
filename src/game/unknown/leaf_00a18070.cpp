/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_creation.h"
#include "tlg_game_name.h"

/* derived names: an object whose table at +0xa0 is used under its spin lock
 * at +0x30c (both reached from the object at +0x38 of the one at +0x108 of
 * the one the pointer at 0x57c9390 holds: 0x1b3f41, 0x1b405a). The table
 * holds its elements by pointer in the array at +0x28, each with its id at
 * +0x24 and its value at +0x28. FUN_00a18070 finds the value of an id, null
 * when no element has it; FUN_00a17f20 hands a value and an id to the
 * table's FUN_00a174c0. The classes and the values are not traced. */
struct Value00a18070; /* derived name */

struct Element00a18070 { /* derived name */
    u8 unknown0[0x24];
    int id;        /* +0x24 */
    u8 value[0x8]; /* +0x28: not traced */
};

struct Table00a18070 { /* derived name */
    u8 unknown0[0x28];
    Array05943280<Element00a18070 *> elements; /* +0x28 */
};

struct Object00a18070 { /* derived name */
    u8 unknown0[0xa0];
    Table00a18070 *table; /* +0xa0 */
    u8 unknowna8[0x264];
    Lock059458a4 lock; /* +0x30c */
};

void FUN_00a174c0(Table00a18070 *table, const Name &value, const Name &id); /* derived name */

/* the value and the id are Names: SetBreakableState and SetBreakableStatus
 * (FUN_001b3e80, FUN_001b41c0) pass the Names of their two string arguments */
void FUN_00a17f20(Object00a18070 *self, const Name &value, const Name &id) /* derived name */
{
    self->lock.lock();
    FUN_00a174c0(self->table, value, id);
    self->lock.unlock();
}

Value00a18070 *FUN_00a18070(Object00a18070 *self, const int &id) /* derived name */
{
    self->lock.lock();
    Value00a18070 *value = 0;
    Table00a18070 *table = self->table;
    for (unsigned i = 0; i < table->elements.size(); ++i) {
        if (table->elements.at(i)->id == id) {
            value = reinterpret_cast<Value00a18070 *>(table->elements.at(i)->value);
            break;
        }
    }
    self->lock.unlock();
    return value;
}
