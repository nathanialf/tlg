/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 8 of the object the pointer at +0x28 holds with
 * its own argument (rsi, left in place), null skipped, as a tail call; slot 8
 * of the vtable at 0x16b1508 (its pointer at 0x16b1558), the vtable stored by
 * FUN_0096a0a0 FUN_0137fd40. The member's class, the argument's type and the
 * return type are not traced. Class and method unknown. */
class Member0137fa80 /* derived name */
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

struct Object0137fa80 { /* derived name */
    u8 unknown0[0x28];
    Member0137fa80 *unknown28;
};

void FUN_0137fa80(Object0137fa80 *self, void *argument) /* derived name */
{
    if (self->unknown28) {
        self->unknown28->slot8(argument);
    }
}
