/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: an object of the list, told the frame's step through slot
 * 12 of its vtable unless one of two flags (+0x40 and +0x48) holds it; the
 * other slots are not traced */
class Item013320b0 /* derived name */
{
  public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void step(float delta); /* derived name */

    u8 unknown8[0x38];
    u8 unknown40; /* +0x40: flags */
    u8 unknown41[0x7];
    u8 unknown48; /* +0x48: flags */
};

struct List013320b0 { /* derived name */
    u8 unknown0[0x10];
    Item013320b0 **items; /* +0x10 */
    unsigned count;       /* +0x18 */
};

struct Object057c9390 { /* derived name: the object, seen from here */
    u8 unknown0[0x20];
    List013320b0 *unknown20; /* +0x20 */
};

struct Object05938c40 { /* derived name: the object, seen from here */
    u8 unknown0[0x19c];
    float unknown19c; /* +0x19c: the frame's step */
};

extern Object057c9390 *D_57c9390;
extern Object05938c40 *D_5938c40;

/* derived name: every item of the list at +0x20 of the object at
 * 0x57c9390 not held by bit 2 of +0x40 or bit 4 of +0x48 is stepped by the
 * step at 0x5938c40, read once (the count read again after each step) */
void FUN_013320b0() /* derived name */
{
    List013320b0 *list = D_57c9390->unknown20;
    const float delta = D_5938c40->unknown19c;
    for (unsigned i = 0; i < list->count; ++i) {
        Item013320b0 *item = list->items[int(i)];
        if (!(item->unknown40 & 2) && !(item->unknown48 & 4))
            item->step(delta);
    }
}
