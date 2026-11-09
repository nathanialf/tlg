/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls its own slot 11 through the vtable with the addresses
 * of the fields at +0x40 and +0x50, as a tail call. The fields' types and the
 * return type are not traced; slot 9 of the vtable at 0x16aa0d0 (its pointer
 * at 0x16aa128), the vtable stored by FUN_004af700 FUN_004af8a0 FUN_004b16e0
 * FUN_004b7d80; slot 9 of the vtable at 0x16aa140 (its pointer at 0x16aa198),
 * the vtable stored by FUN_004b0570 FUN_004b0b10. Class and method unknown. */
class Object004aff80 /* derived name */
{
  public:
    virtual void slot0();                           /* derived name; not traced */
    virtual void slot1();                           /* derived name; not traced */
    virtual void slot2();                           /* derived name; not traced */
    virtual void slot3();                           /* derived name; not traced */
    virtual void slot4();                           /* derived name; not traced */
    virtual void slot5();                           /* derived name; not traced */
    virtual void slot6();                           /* derived name; not traced */
    virtual void slot7();                           /* derived name; not traced */
    virtual void slot8();                           /* derived name; not traced */
    virtual void slot9();                           /* derived name; not traced */
    virtual void slot10();                          /* derived name; not traced */
    virtual void slot11(void *first, void *second); /* derived name; not traced */

    u8 unknown8[0x40 - 8];
    u8 unknown40[0x10]; /* type not traced; its address is passed */
    u8 unknown50[8];    /* type not traced; its address is passed */
};

void FUN_004aff80(Object004aff80 *self) /* derived name */
{
    self->slot11(self->unknown40, self->unknown50);
}
