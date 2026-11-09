/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 5 of the object the pointer at +0x18 holds, null
 * skipped, as a tail call; slot 12 of the vtable at 0x16b1508 (its pointer at
 * 0x16b1578), the vtable stored by FUN_0096a0a0 FUN_0137fd40; slot 14 of the
 * vtable at 0x16cc478 (its pointer at 0x16cc4f8), the vtable stored by
 * FUN_009232e0 FUN_013755d0 FUN_01375710; slot 7 of the vtable at 0x16cc898
 * (its pointer at 0x16cc8e0), the vtable stored by FUN_009240a0; slot 9 of the
 * vtable at 0x16cd1b0 (its pointer at 0x16cd208), the vtable stored by
 * FUN_0096e710; and 2 more. The member's class, its slot and the return type
 * are not traced. Class and method unknown. */
class Member0137c160 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
};

struct Object0137c160 { /* derived name */
    u8 unknown0[0x18];
    Member0137c160 *unknown18;
};

void FUN_0137c160(Object0137c160 *self) /* derived name */
{
    if (self->unknown18) {
        self->unknown18->slot5();
    }
}
