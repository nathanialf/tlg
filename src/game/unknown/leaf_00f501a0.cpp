/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 3 of the vtable at 0x16bf2e8 (no row), written as a free
 * function: gives the object to slot 4 of each child of the record its pointer
 * at +0x8 holds (the 24-byte entries at +0x290, the child at +0x8 of each,
 * their count at +0x298, re-read after every call). The slots' meaning is
 * not traced. */
struct Object00f501a0; /* derived name */

class Child00f501a0 /* derived name */
{
  public:
    virtual void slot0();                       /* derived name; not traced */
    virtual void slot1();                       /* derived name; not traced */
    virtual void slot2();                       /* derived name; not traced */
    virtual void slot3();                       /* derived name; not traced */
    virtual void slot4(Object00f501a0 *object); /* derived name */
};

struct Entry00f501a0 /* derived name */
{
    u8 unknown0[8];
    Child00f501a0 *child; /* +0x8 */
    u8 unknown10[8];
};

struct Record00f501a0 /* derived name */
{
    u8 unknown0[0x290];
    Entry00f501a0 *entries; /* +0x290 */
    unsigned count;         /* +0x298 */

    Entry00f501a0 &at(int index)
    {
        return entries[index];
    } /* derived name */
};

struct Object00f501a0 /* derived name */
{
    u8 unknown0[8];
    Record00f501a0 *record; /* +0x8 */
};

/* the counter is unsigned and the table's index an int: the index is sign-extended at each
 * use (`movsxd`), not widened */
void FUN_00f501a0(Object00f501a0 *self) /* derived name */
{
    for (unsigned i = 0; i < self->record->count; i++)
        self->record->at(i).child->slot4(self);
}
