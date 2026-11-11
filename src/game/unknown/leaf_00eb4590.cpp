/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback FUN_00eb45d0 stores in its table (lea at
 * 0xeb4744): when the object the pointer at +0x28 of the object the pointer at
 * 0x5938c40 holds is not null, returns what gives its slot 16 with the
 * callback's third argument, else returns -0x41. The callback's first two
 * parameters are not read; their types, the member's class and the slot's
 * return type are not traced. */
class Member05938c40_28 /* derived name */
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
    virtual void slot9();               /* derived name; not traced */
    virtual void slot10();              /* derived name; not traced */
    virtual void slot11();              /* derived name; not traced */
    virtual void slot12();              /* derived name; not traced */
    virtual void slot13();              /* derived name; not traced */
    virtual void slot14();              /* derived name; not traced */
    virtual void slot15();              /* derived name; not traced */
    virtual int slot16(void *argument); /* derived name; not traced */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x28];
    Member05938c40_28 *unknown28;
};

extern Object05938c40 *D_5938c40;

int FUN_00eb4590(void *, void *, void *argument) /* derived name */
{
    Member05938c40_28 *member = D_5938c40->unknown28;
    if (!member)
        return -0x41;
    return member->slot16(argument);
}
