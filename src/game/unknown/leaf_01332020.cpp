/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: an object of the list, told the frame's step through slot
 * 10 of its vtable unless one of two flags (+0x40 and +0x48) holds it; the
 * other slots are not traced */
class Item01332020 /* derived name */
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
    virtual void step(float delta); /* derived name */

    u8 unknown8[0x38];
    u8 unknown40; /* +0x40: flags */
    u8 unknown41[0x7];
    u8 unknown48; /* +0x48: flags */
};

struct List01332020 { /* derived name */
    u8 unknown0[0x10];
    Item01332020 **items; /* +0x10 */
    unsigned count;       /* +0x18 */
};

struct Object057c9390 { /* derived name: the object, seen from here */
    u8 unknown0[0x20];
    List01332020 *unknown20; /* +0x20 */
};

struct Object05938c40 { /* derived name: the object, seen from here */
    u8 unknown0[0x19c];
    float unknown19c; /* +0x19c: the frame's step */
};

extern Object057c9390 *D_57c9390;
extern Object05938c40 *D_5938c40;

/* derived name: every item of the list at +0x20 of the object at
 * 0x57c9390 not held by bit 1 of +0x40 or bit 1 of +0x48 is stepped by the
 * step at 0x5938c40, read once (the count read again after each step) */
void FUN_01332020() /* derived name */
{
    List01332020 *list = D_57c9390->unknown20;
    const float delta = D_5938c40->unknown19c;
    for (unsigned i = 0; i < list->count; ++i) {
        Item01332020 *item = list->items[int(i)];
        if (!(item->unknown40 & 1) && !(item->unknown48 & 1))
            item->step(delta);
    }
}
