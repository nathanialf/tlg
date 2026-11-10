/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 8 of the object the pointer at 0xa0 holds, null
 * skipped, as a tail call, passing its own argument on (the slot is loaded
 * into a register before the jump, cookbook 1120); slot 75 of the vtable at
 * 0x16cf698 (its pointer at 0x16cf900); slot 13 of the vtable at 0x16cf9f8
 * (its pointer at 0x16cfa70); and 4 more pointers. The member's class, the
 * argument's type and the return type are not traced. Class and method
 * unknown. */
class Member01398780 /* derived name */
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

struct Object01398780 { /* derived name */
    u8 unknown0[0xa0];
    Member01398780 *unknowna0;
};

void FUN_01398780(Object01398780 *self, void *argument) /* derived name */
{
    if (self->unknowna0) {
        self->unknowna0->slot8(argument);
    }
}
