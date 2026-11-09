/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback of the table FUN_00525530 fills (its address taken
 * there): calls slot 0 of the object the pointer at +0xf0 holds with its own
 * second argument and 1, and returns 0. The member's class and the argument's
 * type are not traced. */
class Member0059f6a0 /* derived name */
{
  public:
    virtual void slot0(void *argument, int value); /* derived name; not traced */
};

struct Object0059f6a0 { /* derived name */
    u8 unknown0[0xf0];
    Member0059f6a0 *unknownf0;
};

int FUN_0059f6a0(Object0059f6a0 *self, void *argument) /* derived name */
{
    self->unknownf0->slot0(argument, 1);
    return 0;
}
