/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 18 of the object the pointer at +0x370 of the
 * record at +0xb0 of the object the pointer at 0x5938c40 holds, a tail call,
 * passing its second argument through (the load kept in rax before `jmp rax`,
 * cookbook 1120); slot 1 of the vtable at 0x16b9b58 (its pointer at 0x16b9b70;
 * no constructor stores it), its slot 0 the empty method FUN_001af750. The
 * object itself is not read. The classes, the argument's type and the return
 * type are not traced. */
struct Object00cf8210; /* derived name */

class Member05938c40_b0_370 /* derived name */
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
    virtual void slot14();               /* derived name; not traced */
    virtual void slot15();               /* derived name; not traced */
    virtual void slot16();               /* derived name; not traced */
    virtual void slot17();               /* derived name; not traced */
    virtual void slot18(void *argument); /* derived name; not traced */
};

struct Member05938c40_b0 { /* derived name */
    u8 unknown0[0x370];
    Member05938c40_b0_370 *unknown370;
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0xb0];
    Member05938c40_b0 *unknownb0;
};

extern Object05938c40 *D_5938c40;

void FUN_00cf8210(Object00cf8210 *, void *argument) /* derived name */
{
    D_5938c40->unknownb0->unknown370->slot18(argument);
}
