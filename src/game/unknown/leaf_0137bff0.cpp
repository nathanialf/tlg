/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 8 of the object the pointer at +0x8 holds with its
 * own argument (rsi, left in place), null skipped, as a tail call; slot 20 of
 * the vtable at 0x16cc478 (its pointer at 0x16cc528), the vtable stored by
 * FUN_009232e0 FUN_013755d0 FUN_01375710; slot 13 of the vtable at 0x16cc898
 * (its pointer at 0x16cc910), the vtable stored by FUN_009240a0; slot 15 of
 * the vtable at 0x16cd1b0 (its pointer at 0x16cd238), the vtable stored by
 * FUN_0096e710; slot 15 of the vtable at 0x16cefb0 (its pointer at 0x16cf038),
 * the vtable stored by FUN_00b383d0; and 1 more. The member's class, the
 * argument's type and the return type are not traced. Class and method
 * unknown. */
class Member0137bff0 /* derived name */
{
  public:
    virtual void slot0();               /* derived name; not traced */
    virtual void slot1();               /* derived name; not traced */
    virtual void slot2();               /* derived name; not traced */
    virtual void slot3();               /* derived name; not traced */
    virtual void slot4();               /* derived name; not traced */
    virtual void slot5();               /* derived name; not traced */
    virtual void slot6();               /* derived name; not traced */
    virtual void slot7();               /* derived name; not traced */
    virtual void slot8(void *argument); /* derived name; not traced */
};

struct Object0137bff0 { /* derived name */
    u8 unknown0[0x8];
    Member0137bff0 *unknown8;
};

void FUN_0137bff0(Object0137bff0 *self, void *argument) /* derived name */
{
    if (self->unknown8) {
        self->unknown8->slot8(argument);
    }
}
