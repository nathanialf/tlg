/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 14 of the object at +0x48 of the object the
 * pointer at 0x5938c40 holds, a tail call, passing its second argument through
 * (the load kept in rax before `jmp rax`, cookbook 1120); slot 2 of the vtable
 * at 0x16b71e0 (its pointer at 0x16b7200), stored by FUN_00b98590, whose slot
 * 0 is the destructor of Object00b997b0. The object itself is not read. The
 * member's class, the argument's type and the return type are not traced. */
class Object00b997b0;

class Member05938c40_48 /* derived name */
{
  public:
    virtual void slot0();                /* derived name; not traced */
    virtual void slot1();                /* derived name; not traced */
    virtual void slot2();                /* derived name; not traced */
    virtual void slot3();                /* derived name; not traced */
    virtual void slot4();                /* derived name; not traced */
    virtual void slot5();                /* derived name; not traced */
    virtual void slot6();                /* derived name; not traced */
    virtual void slot7();                /* derived name; not traced */
    virtual void slot8();                /* derived name; not traced */
    virtual void slot9();                /* derived name; not traced */
    virtual void slot10();               /* derived name; not traced */
    virtual void slot11();               /* derived name; not traced */
    virtual void slot12();               /* derived name; not traced */
    virtual void slot13();               /* derived name; not traced */
    virtual void slot14(void *argument); /* derived name; not traced */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x48];
    Member05938c40_48 *unknown48;
};

extern Object05938c40 *D_5938c40;

void FUN_00b99790(Object00b997b0 *, void *argument) /* derived name */
{
    D_5938c40->unknown48->slot14(argument);
}
