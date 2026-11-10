/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 8 of the object the pointer at 0xf8 holds, null
 * skipped, as a tail call, passing its own argument on (the slot is loaded
 * into a register before the jump, cookbook 1120); slot 21 of the vtable at
 * 0x16b5ae8 (its pointer at 0x16b5ba0). The member's class, the argument's
 * type and the return type are not traced. Class and method unknown. */
class Member01396d20 /* derived name */
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

struct Object01396d20 { /* derived name */
    u8 unknown0[0xf8];
    Member01396d20 *unknownf8;
};

void FUN_01396d20(Object01396d20 *self, void *argument) /* derived name */
{
    if (self->unknownf8) {
        self->unknownf8->slot8(argument);
    }
}
