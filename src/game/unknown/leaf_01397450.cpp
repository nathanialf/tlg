/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 5 of the object the pointer at +0x108 holds, null
 * skipped, as a tail call; slot 15 of the vtable at 0x16b5ae8 (its pointer at
 * 0x16b5b70), the vtable stored by FUN_00b3f8e0. The member's class, its slot
 * and the return type are not traced. Class and method unknown. */
class Member01397450 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
};

struct Object01397450 { /* derived name */
    u8 unknown0[0x108];
    Member01397450 *unknown108;
};

void FUN_01397450(Object01397450 *self) /* derived name */
{
    if (self->unknown108) {
        self->unknown108->slot5();
    }
}
