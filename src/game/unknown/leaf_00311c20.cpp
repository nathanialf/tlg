/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 22 of the vtable at 0x16a8430 (stored by FUN_002f9860
 * and FUN_002fed80; no row): it runs the base class's version FUN_00a8fdd0
 * (a slot of the vtables 0x16a9790, 0x16a9c68 and 0x16b29f0), which rebuilds
 * the 0x420-byte tables at +0x158 and +0x160, then adds one more entry to
 * the table at +0x160: a new object of the class whose vtable is at 0x16b2898
 * (config/vtables.derived.base.txt) under the key D_5828fc0. FUN_00c1c2a0 is
 * the table's add (the key, then the entry). The key is read before the
 * allocation, the table pointer before the test: both are the call's
 * arguments in their order. */
struct Object00c1c2a0; /* derived name */

/* derived names: an entry of the table. The base's int at +0x8 starts at 0
 * and is stored before the derived class's vtable (the base's constructor
 * runs first; FUN_00a8fdd0 builds its two entries, 0x16b2898 and 0x16b6bf8,
 * the same way). Neither destructor is traced. */
class Entry00c1c2a0 /* derived name */
{
  public:
    Entry00c1c2a0() : unknown8(0) {}

    virtual ~Entry00c1c2a0() {}

  private:
    int unknown8; /* +0x8 */
};

/* derived names: the entry of 0x18 bytes whose vtable is at 0x16b2898; its
 * field at +0x10 is not set by the constructor. Its destructor is empty and
 * out of line, the class's key function, so this file emits the vtable: the
 * linker folded it and the deleting one onto the shared bodies 0x1af750 and
 * 0x21a00 (slots 0 and 1). Slot 2 is 0x69a0 (shared with the vtable at
 * 0x16b6be8), slots 3 and 4 FUN_00a85560 and FUN_00a85710 (leaf_00a85710.cpp,
 * written as a free function), declared here untraced. */
class Object016b2898 : public Entry00c1c2a0 /* derived name */
{
  public:
    virtual ~Object016b2898();
    virtual void slot2(); /* derived name; 0x69a0, not traced */
    virtual void slot3(); /* derived name; FUN_00a85560, not traced */
    virtual void slot4(); /* derived name; FUN_00a85710, not traced */

  private:
    void *unknown10; /* +0x10 */
};

struct Object00311c20 /* derived name */
{
    u8 unknown0[0x160];
    Object00c1c2a0 *table160; /* +0x160 */
};

extern u64 D_5828fc0; /* derived name: the entry's key */

void FUN_00a8fdd0(Object00311c20 *self);                                 /* derived name */
void FUN_00c1c2a0(Object00c1c2a0 *table, u64 key, Entry00c1c2a0 *entry); /* derived name */

Object016b2898::~Object016b2898() {}

void FUN_00311c20(Object00311c20 *self) /* derived name */
{
    FUN_00a8fdd0(self);
    Object00c1c2a0 *table = self->table160;
    if (table != 0)
        FUN_00c1c2a0(table, D_5828fc0, new Object016b2898);
}
