/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback (its address taken by FUN_004a2de0): calls slot 9
 * of the object the pointer at +0x10 holds with the int at +0x18 and the float
 * at +0x1c, as a tail call. The member's class and the return type are not
 * traced. */
class Member004b7be0 /* derived name */
{
  public:
    virtual void slot0();               /* derived name; not traced */
    virtual void slot1();               /* derived name; not traced */
    virtual void slot2();               /* derived name; not traced */
    virtual void slot3();               /* derived name; not traced */
    virtual void slot4();               /* derived name; not traced */
    virtual void slot5();               /* derived name; not traced */
    virtual void slot6();               /* derived name; not traced */
    virtual void slot7();               /* derived name; not traced */
    virtual void slot8();               /* derived name; not traced */
    virtual void slot9(int a, float b); /* derived name; not traced */
};

struct Object004b7be0 { /* derived name */
    u8 unknown0[0x10];
    Member004b7be0 *unknown10;
    int unknown18;
    float unknown1c;
};

void FUN_004b7be0(Object004b7be0 *self) /* derived name */
{
    self->unknown10->slot9(self->unknown18, self->unknown1c);
}
