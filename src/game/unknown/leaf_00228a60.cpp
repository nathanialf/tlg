/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 11 of the object the pointer at +0x10 holds with
 * the float at +0x18, as a tail call; reached from FUN_00227900 (its address
 * taken). The member's class and the return type are not traced. Class and
 * method unknown. */
class Member00228a60 /* derived name */
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
    virtual void slot11(float value); /* derived name; not traced */
};

struct Object00228a60 { /* derived name */
    u8 unknown0[0x10];
    Member00228a60 *unknown10;
    float unknown18;
};

void FUN_00228a60(Object00228a60 *self) /* derived name */
{
    self->unknown10->slot11(self->unknown18);
}
