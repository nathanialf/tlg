/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 5 of the object the pointer at +0x148 holds, null
 * skipped, as a tail call; slot 11 of the vtable at 0x16b0fb0 (its pointer at
 * 0x16b1018), the vtable stored by FUN_00958460; slot 11 of the vtable at
 * 0x16c7b78 (its pointer at 0x16c7be0), the vtable stored by FUN_00958460
 * FUN_0137e6e0. The member's class, its slot and the return type are not
 * traced. Class and method unknown. */
class Member0137e150 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
};

struct Object0137e150 { /* derived name */
    u8 unknown0[0x148];
    Member0137e150 *unknown148;
};

void FUN_0137e150(Object0137e150 *self) /* derived name */
{
    if (self->unknown148) {
        self->unknown148->slot5();
    }
}
