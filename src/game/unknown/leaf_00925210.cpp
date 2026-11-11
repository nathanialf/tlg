/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 22 of the vtable at 0x16b0d90 (its pointer at
 * 0x16b0e50), beside FUN_00925260 (slot 23): when bit 1 of the flags at
 * +0x274 is set, clears bits 2 and 3 of them and calls slots 15 and 16 of the
 * object the pointer at +0x258 holds with 0 (the second a tail call). The
 * member's class is not traced. Class and method unknown. */
class Member00925210_258 /* derived name */
{
  public:
    virtual void slot0();           /* derived name; not traced */
    virtual void slot1();           /* derived name; not traced */
    virtual void slot2();           /* derived name; not traced */
    virtual void slot3();           /* derived name; not traced */
    virtual void slot4();           /* derived name; not traced */
    virtual void slot5();           /* derived name; not traced */
    virtual void slot6();           /* derived name; not traced */
    virtual void slot7();           /* derived name; not traced */
    virtual void slot8();           /* derived name; not traced */
    virtual void slot9();           /* derived name; not traced */
    virtual void slot10();          /* derived name; not traced */
    virtual void slot11();          /* derived name; not traced */
    virtual void slot12();          /* derived name; not traced */
    virtual void slot13();          /* derived name; not traced */
    virtual void slot14();          /* derived name; not traced */
    virtual void slot15(int value); /* derived name; not traced */
    virtual void slot16(int value); /* derived name; not traced */
};

struct Object00925210 /* derived name */
{
    u8 unknown0[0x258];
    Member00925210_258 *unknown258; /* +0x258 */
    u8 unknown260[0x14];
    unsigned unknown274; /* +0x274: flags */
};

void FUN_00925210(Object00925210 *self) /* derived name */
{
    if (self->unknown274 & 2) {
        self->unknown274 &= ~0xcu;
        self->unknown258->slot15(0);
        self->unknown258->slot16(0);
    }
}
