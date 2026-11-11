/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback (its address taken by FUN_00ce1d20 (lea at 0xce1ded)): calls slot
 * 13 of the object at +0x10 with the float at +0x18, as a tail call, when that
 * object's int at +0xdc is zero. Record and method unknown. */
class Base013b0c40 /* derived name */
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
    virtual void slot10();            /* derived name; not traced */
    virtual void slot11();            /* derived name; not traced */
    virtual void slot12();            /* derived name; not traced */
    virtual void slot13(float value); /* derived name */
};

struct Target013b0c40 : Base013b0c40 { /* derived name */
    u8 unknown8[0xd4];
    int unknowndc;
};

struct Record013b0c40 { /* derived name */
    u8 unknown0[0x10];
    Target013b0c40 *unknown10;
    float unknown18;
};

void FUN_013b0c40(Record013b0c40 *record) /* derived name */
{
    Target013b0c40 *target = record->unknown10;
    if (target->unknowndc == 0) {
        target->slot13(record->unknown18);
    }
}
