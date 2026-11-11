/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 23 of the vtable at 0x16b0d90 (its pointer at
 * 0x16b0e58), stored by FUN_00924230 and FUN_0137c320: when bit 1 of the
 * flags at +0x274 is set, clears bits 2 and 3 of them, calls slot 11 of the
 * object the pointer at +0x258 holds when there is one, and copies the int at
 * +0x288 to +0x284. The member's class and the slot's result are not traced.
 * Class and method unknown. */
class Member00925260_258 /* derived name */
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
};

struct Object00925260 /* derived name */
{
    u8 unknown0[0x258];
    Member00925260_258 *unknown258; /* +0x258 */
    u8 unknown260[0x14];
    unsigned unknown274; /* +0x274: flags */
    u8 unknown278[0xc];
    int unknown284; /* +0x284 */
    int unknown288; /* +0x288 */
};

void FUN_00925260(Object00925260 *self) /* derived name */
{
    if (self->unknown274 & 2) {
        self->unknown274 &= ~0xcu;
        if (self->unknown258)
            self->unknown258->slot11();
        self->unknown284 = self->unknown288;
    }
}
