/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes the object and its second argument to FUN_00c1a0c0,
 * then, when the pointer at +0x50 is not null, calls slot 5 of the object it
 * holds with the argument, a tail call; slot 5 of the vtable at 0x16b8040 (its
 * pointer at 0x16b8078), stored by FUN_00c19f10 and FUN_00c1a5e0. The types
 * and the return types are not traced. */
class Member00c1ac40_50 /* derived name */
{
  public:
    virtual void slot0();               /* derived name; not traced */
    virtual void slot1();               /* derived name; not traced */
    virtual void slot2();               /* derived name; not traced */
    virtual void slot3();               /* derived name; not traced */
    virtual void slot4();               /* derived name; not traced */
    virtual void slot5(void *argument); /* derived name; not traced */
};

struct Object00c1ac40 { /* derived name */
    u8 unknown0[0x50];
    Member00c1ac40_50 *unknown50;
};

void FUN_00c1a0c0(Object00c1ac40 *object, void *argument); /* derived name */

void FUN_00c1ac40(Object00c1ac40 *self, void *argument) /* derived name */
{
    FUN_00c1a0c0(self, argument);
    if (self->unknown50)
        self->unknown50->slot5(argument);
}
