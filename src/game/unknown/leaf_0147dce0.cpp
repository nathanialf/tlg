/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls its own slot 8 (FUN_01241ec0 in this vtable) through
 * the vtable with the address of the field at +0x2d0 of the record the pointer
 * at +0x8 holds, as a tail call; slot 4 of the vtable at 0x16d6b98 (its
 * pointer at 0x16d6bc8), the vtable stored by FUN_0122be10. The field's type
 * and the return type are not traced. Class and method unknown. */
struct Record0147dce0 { /* derived name */
    u8 unknown0[0x2d0];
    u8 unknown2d0; /* type not traced; its address is passed */
};

class Object0147dce0 /* derived name */
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
    virtual void FUN_01241ec0(void *argument); /* derived name */

    Record0147dce0 *unknown8;
};

void FUN_0147dce0(Object0147dce0 *self) /* derived name */
{
    self->FUN_01241ec0(&self->unknown8->unknown2d0);
}
