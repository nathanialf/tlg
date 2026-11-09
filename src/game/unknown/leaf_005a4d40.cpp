/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback of the table FUN_00525530 fills (its address taken
 * there): calls slot 0 of the object the pointer at +0xf0 holds with its own
 * second argument and 4, and returns 0. The member's class and the argument's
 * type are not traced. */
class Member005a4d40 /* derived name */
{
  public:
    virtual void slot0(void *argument, int value); /* derived name; not traced */
};

struct Object005a4d40 { /* derived name */
    u8 unknown0[0xf0];
    Member005a4d40 *unknownf0;
};

int FUN_005a4d40(Object005a4d40 *self, void *argument) /* derived name */
{
    self->unknownf0->slot0(argument, 4);
    return 0;
}
