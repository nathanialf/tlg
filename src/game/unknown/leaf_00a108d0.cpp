/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"

/* derived names: under the lock of the array at +0x10 of the object at +0x38
 * of the one at +0x58 of the one the pointer at 0x57c9390 holds, every
 * element (the count read once) is asked its slot 11 and, where that returns
 * nonzero, given its slot 12 (`call [rax+0x58]`, `call [rax+0x60]`, the
 * element read again for the second). The classes and the slots are not
 * traced. */
class Element00a108d0 /* derived name */
{
  public:
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
    virtual void unknown3();
    virtual void unknown4();
    virtual void unknown5();
    virtual void unknown6();
    virtual void unknown7();
    virtual void unknown8();
    virtual void unknown9();
    virtual void unknown10();
    virtual int unknown11();
    virtual void unknown12();
};

struct List00a108d0 { /* derived name */
    u8 unknown0[0x10];
    Array01343a80<Element00a108d0 *> elements; /* +0x10 */
};

struct Owner00a108d0 { /* derived name */
    u8 unknown0[0x38];
    List00a108d0 *list; /* +0x38 */
};

struct Object057c9390 { /* derived name: the object, seen from here */
    u8 unknown0[0x58];
    Owner00a108d0 *unknown58; /* +0x58 */
};

extern Object057c9390 *D_57c9390;

void FUN_00a108d0() /* derived name */
{
    List00a108d0 *list = D_57c9390->unknown58->list;
    list->elements.lock.lock();
    const unsigned count = list->elements.size();
    for (unsigned i = 0; i < count; ++i) {
        if (list->elements.at(i)->unknown11())
            list->elements.at(i)->unknown12();
    }
    list->elements.lock.unlock();
}
