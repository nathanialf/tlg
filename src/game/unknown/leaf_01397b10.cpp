/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 5 of the object the pointer at +0x90 holds, null
 * skipped, as a tail call; slot 79 of the vtable at 0x16cf698 (its pointer at
 * 0x16cf920), the vtable stored by FUN_00b40b80; slot 20 of the vtable at
 * 0x16cf9f8 (its pointer at 0x16cfaa8), the vtable stored by FUN_00b40f10;
 * slot 20 of the vtable at 0x16cfb98 (its pointer at 0x16cfc48), the vtable
 * stored by FUN_00b40f10. The member's class, its slot and the return type are
 * not traced. Class and method unknown. */
class Member01397b10 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
};

struct Object01397b10 { /* derived name */
    u8 unknown0[0x90];
    Member01397b10 *unknown90;
};

void FUN_01397b10(Object01397b10 *self) /* derived name */
{
    if (self->unknown90) {
        self->unknown90->slot5();
    }
}
