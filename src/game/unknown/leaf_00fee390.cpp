/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 9 of the vtable at 0x16c0478 (address point
 * 0x16c0488) and of the vtables after it that keep it (0x16c04d0 to
 * 0x16c06b0). It asks the provider at +0x1e8 of the record at +0x18 for the
 * entry of the record's key at +0x8 (with its ints at +0x1c and +0x20,
 * provider slot 8) and, when the entry's flag bit 0 at +0x28 is set, hands
 * the argument and the entry to this object's slot 6 twice, with 0 and then
 * 1. FUN_0125aa60 (leaf_0125aa60.cpp) has the same bytes. The record's, the
 * provider's and the entry's classes are not traced. */
struct Entry00fee390 { /* derived name */
    u8 unknown0[0x28];
    u8 flags28; /* +0x28: bit 0 tested */
};

class Provider00fee390 /* derived name */
{
  public:
    virtual void slot0();                                           /* derived name; not traced */
    virtual void slot1();                                           /* derived name; not traced */
    virtual void slot2();                                           /* derived name; not traced */
    virtual void slot3();                                           /* derived name; not traced */
    virtual void slot4();                                           /* derived name; not traced */
    virtual void slot5();                                           /* derived name; not traced */
    virtual void slot6();                                           /* derived name; not traced */
    virtual void slot7();                                           /* derived name; not traced */
    virtual Entry00fee390 *slot8(void *key, int first, int second); /* derived name */
};

struct Record00fee390 { /* derived name */
    u8 unknown0[0x8];
    void *key; /* +0x8 */
    u8 unknown10[0xc];
    int unknown1c;
    int unknown20;
    u8 unknown24[0x1e8 - 0x24];
    Provider00fee390 *provider; /* +0x1e8 */
};

class Object00fee390 /* derived name */
{
  public:
    virtual ~Object00fee390();
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(void *argument, Entry00fee390 *entry, int which); /* derived name */
    virtual void slot7();               /* derived name; not traced */
    virtual void slot8();               /* derived name; not traced */
    virtual void slot9(void *argument); /* derived name */

    u8 unknown8[0x10];
    Record00fee390 *record; /* +0x18 */
};

// NONMATCHING: list-ilp order: the base loads the provider's vptr (`mov r8, [rdi]`) before the two
// ints at +0x1c and +0x20, the build after them (the IR has the base's order); 15 of 37 before it
void Object00fee390::slot9(void *argument)
{
    Record00fee390 *record = this->record;
    if (record->key && record->provider) {
        Entry00fee390 *entry =
            record->provider->slot8(record->key, record->unknown1c, record->unknown20);
        if (entry && (entry->flags28 & 1)) {
            slot6(argument, entry, 0);
            slot6(argument, entry, 1);
        }
    }
}
