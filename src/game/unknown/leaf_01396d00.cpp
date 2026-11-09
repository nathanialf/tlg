/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 5 of the object the pointer at +0xf8 holds, null
 * skipped, as a tail call; slot 20 of the vtable at 0x16b5ae8 (its pointer at
 * 0x16b5b98), the vtable stored by FUN_00b3f8e0. The member's class, its slot
 * and the return type are not traced. Class and method unknown. */
class Member01396d00 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
};

struct Object01396d00 { /* derived name */
    u8 unknown0[0xf8];
    Member01396d00 *unknownf8;
};

void FUN_01396d00(Object01396d00 *self) /* derived name */
{
    if (self->unknownf8) {
        self->unknownf8->slot5();
    }
}
