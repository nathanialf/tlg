/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 8 of the object the pointer at +0x18 holds with
 * its own argument (rsi, left in place), null skipped, as a tail call; slot 13
 * of the vtable at 0x16b1508 (its pointer at 0x16b1580), the vtable stored by
 * FUN_0096a0a0 FUN_0137fd40; slot 15 of the vtable at 0x16cc478 (its pointer
 * at 0x16cc500), the vtable stored by FUN_009232e0 FUN_013755d0 FUN_01375710;
 * slot 8 of the vtable at 0x16cc898 (its pointer at 0x16cc8e8), the vtable
 * stored by FUN_009240a0; slot 10 of the vtable at 0x16cd1b0 (its pointer at
 * 0x16cd210), the vtable stored by FUN_0096e710; and 2 more. The member's
 * class, the argument's type and the return type are not traced. Class and
 * method unknown. */
class Member0137c170 /* derived name */
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

struct Object0137c170 { /* derived name */
    u8 unknown0[0x18];
    Member0137c170 *unknown18;
};

void FUN_0137c170(Object0137c170 *self, void *argument) /* derived name */
{
    if (self->unknown18) {
        self->unknown18->slot8(argument);
    }
}
