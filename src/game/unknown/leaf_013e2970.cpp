/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls its own slot 8 (FUN_00faf3a0 in this vtable) through
 * the vtable with the address of the field at +0x2f0 of the record the pointer
 * at +0x8 holds, as a tail call; slot 4 of the vtable at 0x16d3f88 (its
 * pointer at 0x16d3fb8), the vtable stored by FUN_00f9ab50. The field's type
 * and the return type are not traced. Class and method unknown. */
struct Record013e2970 { /* derived name */
    u8 unknown0[0x2f0];
    u8 unknown2f0; /* type not traced; its address is passed */
};

class Object013e2970 /* derived name */
{
  public:
    virtual void slot0();                      /* derived name; not traced */
    virtual void slot1();                      /* derived name; not traced */
    virtual void slot2();                      /* derived name; not traced */
    virtual void slot3();                      /* derived name; not traced */
    virtual void slot4();                      /* derived name; not traced */
    virtual void slot5();                      /* derived name; not traced */
    virtual void slot6();                      /* derived name; not traced */
    virtual void slot7();                      /* derived name; not traced */
    virtual void FUN_00faf3a0(void *argument); /* derived name */

    Record013e2970 *unknown8;
};

void FUN_013e2970(Object013e2970 *self) /* derived name */
{
    self->FUN_00faf3a0(&self->unknown8->unknown2f0);
}
