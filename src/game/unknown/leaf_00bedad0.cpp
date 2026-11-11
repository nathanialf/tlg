/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback (its address taken by FUN_013a4b10, lea at
 * 0x13a4b86): calls slot 10 of the object at +0x10 with the float at +0x18, as
 * a tail call, when that object's int at +0x30 is set and bit 2 of its flags
 * at +0x4c is clear. Record and method unknown. */
class Base00bedad0 /* derived name */
{
  public:
    virtual void slot0();             /* derived name; not traced */
    virtual void slot1();             /* derived name; not traced */
    virtual void slot2();             /* derived name; not traced */
    virtual void slot3();             /* derived name; not traced */
    virtual void slot4();             /* derived name; not traced */
    virtual void slot5();             /* derived name; not traced */
    virtual void slot6();             /* derived name; not traced */
    virtual void slot7();             /* derived name; not traced */
    virtual void slot8();             /* derived name; not traced */
    virtual void slot9();             /* derived name; not traced */
    virtual void slot10(float value); /* derived name */
};

struct Target00bedad0 : Base00bedad0 { /* derived name */
    u8 unknown8[0x28];
    int unknown30;
    u8 unknown34[0x18];
    u32 unknown4c;
};

struct Record00bedad0 { /* derived name */
    u8 unknown0[0x10];
    Target00bedad0 *unknown10;
    float unknown18;
};

void FUN_00bedad0(Record00bedad0 *record) /* derived name */
{
    Target00bedad0 *target = record->unknown10;
    if (target->unknown30 != 0 && !(target->unknown4c & 4)) {
        target->slot10(record->unknown18);
    }
}
