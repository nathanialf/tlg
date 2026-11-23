/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 5 of the vtables at 0x16c2640, 0x16c2690 and 0x16c26e0
 * (eight slots, the first the empty body at 0x1af750: no virtual
 * destructor), the three classes FUN_0126a510 builds; slots 4 and 5 are the
 * same in all three, so a base the three share. It asks the provider at
 * +0x1e8 of the record at +0x18 for the entry of the record's key at +0x8
 * (with its ints at +0x1c and +0x20, provider slot 8) and, when the entry's
 * flag bit 0 at +0x28 is set, hands the argument and the entry to this
 * object's slot 6 twice, with 0 and then 1: FUN_00fee390's bytes (slot 9 of
 * 0x16c0478, leaf_00fee390.cpp). The record's, the provider's and the
 * entry's classes are not traced. */
struct Entry0125aa60 { /* derived name */
    u8 unknown0[0x28];
    u8 flags28; /* +0x28: bit 0 tested */
};

class Provider0125aa60 /* derived name */
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
    virtual Entry0125aa60 *slot8(void *key, int first, int second); /* derived name */
};

struct Record0125aa60 { /* derived name */
    u8 unknown0[0x8];
    void *key; /* +0x8 */
    u8 unknown10[0xc];
    int unknown1c;
    int unknown20;
    u8 unknown24[0x1e8 - 0x24];
    Provider0125aa60 *provider; /* +0x1e8 */
};

class Object0125aa60 /* derived name */
{
  public:
    virtual void slot0();               /* derived name; 0x1af750 */
    virtual void slot1();               /* derived name; not traced */
    virtual void slot2();               /* derived name; not traced */
    virtual void slot3();               /* derived name; not traced */
    virtual void slot4();               /* derived name; FUN_0125aa30, not traced */
    virtual void slot5(void *argument); /* derived name */
    virtual void slot6(void *argument, Entry0125aa60 *entry, int which); /* derived name */
    virtual void slot7(); /* derived name; 0x1af750 */

    u8 unknown8[0x10];
    Record0125aa60 *record; /* +0x18 */
};

void Object0125aa60::slot5(void *argument)
{
    Record0125aa60 *record = this->record;
    if (record->key && record->provider) {
        Entry0125aa60 *entry =
            record->provider->slot8(record->key, record->unknown1c, record->unknown20);
        if (entry && (entry->flags28 & 1)) {
            slot6(argument, entry, 0);
            slot6(argument, entry, 1);
        }
    }
}
