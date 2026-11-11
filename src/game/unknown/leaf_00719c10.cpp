/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: unless bit 0 of the byte at +0xad4 of the object is set,
 * calls the object's slot 15 with the float at +0x19c of the object the
 * pointer at 0x5938c40 holds, a tail call; slot 11 of the vtable at 0x16ac7c8
 * (its pointer at 0x16ac830), stored by FUN_00704230 and its destructor
 * FUN_00712f40. The class's other slots and the return type are not traced. */
class Object00719c10 /* derived name */
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
    virtual void slot15(float value); /* derived name; not traced */

    u8 unknown8[0xacc];
    u8 unknownAd4; /* +0xad4: bit 0 tested */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x19c];
    float unknown19c;
};

extern Object05938c40 *D_5938c40;

void FUN_00719c10(Object00719c10 *self) /* derived name */
{
    if (!(self->unknownAd4 & 1))
        self->slot15(D_5938c40->unknown19c);
}
