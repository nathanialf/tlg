/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback (its address taken by FUN_013a3900, lea at
 * 0x13a4940): when the int at +0x30 of the object at +0x10 is set, calls its
 * slot 9 with the float at +0x18, else its slot 11, as a tail call. Record and
 * methods unknown. */
class Base00bedaa0 /* derived name */
{
  public:
    virtual void slot0();            /* derived name; not traced */
    virtual void slot1();            /* derived name; not traced */
    virtual void slot2();            /* derived name; not traced */
    virtual void slot3();            /* derived name; not traced */
    virtual void slot4();            /* derived name; not traced */
    virtual void slot5();            /* derived name; not traced */
    virtual void slot6();            /* derived name; not traced */
    virtual void slot7();            /* derived name; not traced */
    virtual void slot8();            /* derived name; not traced */
    virtual void slot9(float value); /* derived name */
    virtual void slot10();           /* derived name; not traced */
    virtual void slot11();           /* derived name */
};

struct Target00bedaa0 : Base00bedaa0 { /* derived name */
    u8 unknown8[0x28];
    int unknown30;
};

struct Record00bedaa0 { /* derived name */
    u8 unknown0[0x10];
    Target00bedaa0 *unknown10;
    float unknown18;
};

void FUN_00bedaa0(Record00bedaa0 *record) /* derived name */
{
    Target00bedaa0 *target = record->unknown10;
    if (target->unknown30 != 0) {
        target->slot9(record->unknown18);
    } else {
        target->slot11();
    }
}
