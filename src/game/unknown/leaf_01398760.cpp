/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 5 of the object the pointer at +0xa0 holds, null
 * skipped, as a tail call; slot 74 of the vtable at 0x16cf698 (its pointer at
 * 0x16cf8f8), the vtable stored by FUN_00b40b80; slot 12 of the vtable at
 * 0x16cf9f8 (its pointer at 0x16cfa68), the vtable stored by FUN_00b40f10;
 * slot 12 of the vtable at 0x16cfb98 (its pointer at 0x16cfc08), the vtable
 * stored by FUN_00b40f10; slot 58 of the vtable at 0x16cfb98 (its pointer at
 * 0x16cfd78), the vtable stored by FUN_00b40f10; and 2 more. The member's
 * class, its slot and the return type are not traced. Class and method
 * unknown. */
class Member01398760 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
};

struct Object01398760 { /* derived name */
    u8 unknown0[0xa0];
    Member01398760 *unknowna0;
};

void FUN_01398760(Object01398760 *self) /* derived name */
{
    if (self->unknowna0) {
        self->unknowna0->slot5();
    }
}
