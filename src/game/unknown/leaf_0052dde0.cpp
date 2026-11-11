/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the call slot (slot 2) of the callable holder whose vtable
 * is at 0x16ab498 (stored by FUN_0052c710 FUN_0052d5b0 FUN_0052dda0): the
 * holder is not read. Calls slot 17 of the object it is given with a float:
 * the one at +0x24 of the record at +0x98 of the object at 0x57c9390 when the
 * given object's int at +0xdc is nonzero, else the one at +0x19c of the object
 * at 0x5938c40 (the two addresses selected, then one load), as a tail call.
 * The types are not traced beyond these fields. */
struct Object0052dde0; /* derived name */

class Target0052dde0 /* derived name */
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
    virtual void slot13();            /* derived name; not traced */
    virtual void slot14();            /* derived name; not traced */
    virtual void slot15();            /* derived name; not traced */
    virtual void slot16();            /* derived name; not traced */
    virtual void slot17(float value); /* derived name */

    u8 unknown8[0xd4];
    int unknowndc; /* +0xdc */
};

struct Member057c9390_98 { /* derived name */
    u8 unknown0[0x24];
    float unknown24; /* +0x24 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x98];
    Member057c9390_98 *unknown98; /* +0x98 */
};

extern Object057c9390 *D_57c9390;

struct Object05938c40 { /* derived name */
    u8 unknown0[0x19c];
    float unknown19c; /* +0x19c */
};

extern Object05938c40 *D_5938c40;

// NONMATCHING: greedy's assignment: every instruction is the base's but the slot's address takes rcx where the base reuses rax (`mov rax, [rcx + 0x88]; jmp rax`); with the value written inline as a conditional the slot is loaded before the branch
void FUN_0052dde0(Object0052dde0 *, Target0052dde0 &target) /* derived name */
{
    float value;
    if (target.unknowndc != 0)
        value = D_57c9390->unknown98->unknown24;
    else
        value = D_5938c40->unknown19c;
    target.slot17(value);
}
