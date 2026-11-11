/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 14 of the object at +0xb0 of the object the
 * pointer at 0x5938c40 holds, a tail call; slot 5 of the vtable at 0x16d0ec8
 * (its pointer at 0x16d0f00, stored by FUN_00c3caa0), one of the 109 vtables
 * whose slot 0 is the destructor of Object013a6a50 (FUN_013a6a50). The object
 * itself is not read. The member's class, the argument's type and the return
 * type are not traced. */
class Object013a6a50; /* derived name */

class Member05938c40_b0 /* derived name */
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
    virtual void slot13(); /* derived name; not traced */
    virtual void slot14(); /* derived name; not traced */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0xb0];
    Member05938c40_b0 *unknownb0;
};

extern Object05938c40 *D_5938c40;

void FUN_013a5540(Object013a6a50 *) /* derived name */
{
    D_5938c40->unknownb0->slot14();
}
