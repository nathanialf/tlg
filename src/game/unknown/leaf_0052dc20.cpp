/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16ab418 (+0x20 from the vtable stored at
 * 0x16ab3f8): calls its argument's slot 12 with a float, a tail call: the
 * float at +0x24 of the record at +0x98 of the object the pointer at 0x57c9390
 * holds when bit 1 of the argument's byte at +0x40 is set, else the float at
 * +0x19c of the object the pointer at 0x5938c40 holds. The object itself is
 * not read; the classes and the return types are not traced. */
class Argument0052dc20 /* derived name */
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
    virtual void slot12(float value); /* derived name; not traced */

    u8 unknown8[0x38];
    u8 unknown40;
};

struct Object0052dc20; /* derived name */

struct Member057c9390_98 { /* derived name */
    u8 unknown0[0x24];
    float unknown24;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x98];
    Member057c9390_98 *unknown98;
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x19c];
    float unknown19c;
};

extern Object057c9390 *D_57c9390;
extern Object05938c40 *D_5938c40;

// NONMATCHING: greedy's assignment: all but the last two instructions are the base's; slot 12's address takes rcx where the base reuses rax (the selected address dead after its load)
void FUN_0052dc20(Object0052dc20 *, Argument0052dc20 *argument) /* derived name */
{
    float value =
        (argument->unknown40 & 2) ? D_57c9390->unknown98->unknown24 : D_5938c40->unknown19c;
    argument->slot12(value);
}
