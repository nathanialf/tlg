/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns, sign-extended to 64 bits (`cdqe` after the call),
 * the int slot 13 of the object at +0x28 of the object the pointer at
 * 0x5938c40 holds returns; slot 5 of the vtable at 0x16d0228 (its pointer at
 * 0x16d0260), the vtable stored by FUN_00b98590 beside 0x16b71e0, its slot 0
 * the empty method FUN_001af750. The object itself is not read. The member's
 * class, the arguments' types and the return type are not traced. */
struct Object0139dfb0; /* derived name */

class Member05938c40_28 /* derived name */
{
  public:
    virtual void slot0();  /* derived name; not traced */
    virtual void slot1();  /* derived name; not traced */
    virtual void slot2();  /* derived name; not traced */
    virtual void slot3();  /* derived name; not traced */
    virtual void slot4();  /* derived name; not traced */
    virtual void slot5();  /* derived name; not traced */
    virtual void slot6();  /* derived name; not traced */
    virtual void slot7();  /* derived name; not traced */
    virtual void slot8();  /* derived name; not traced */
    virtual void slot9();  /* derived name; not traced */
    virtual void slot10(); /* derived name; not traced */
    virtual void slot11(); /* derived name; not traced */
    virtual void slot12(); /* derived name; not traced */
    virtual int slot13();  /* derived name; not traced */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x28];
    Member05938c40_28 *unknown28;
};

extern Object05938c40 *D_5938c40;

long FUN_0139e010(Object0139dfb0 *) /* derived name */
{
    return D_5938c40->unknown28->slot13();
}
