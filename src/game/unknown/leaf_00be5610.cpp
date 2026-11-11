/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16b7a88 (+0x48 from the vtable stored at
 * 0x16b7a40): when the pointer at +0xd8 is set, returns what FUN_00be1c30
 * returns for the object and what its slot 5 returns, a tail call; else 0. The
 * class and the types are not traced. */
class Object00be5610 /* derived name */
{
  public:
    virtual void slot0();  /* derived name; not traced */
    virtual void slot1();  /* derived name; not traced */
    virtual void slot2();  /* derived name; not traced */
    virtual void slot3();  /* derived name; not traced */
    virtual void slot4();  /* derived name; not traced */
    virtual void *slot5(); /* derived name; not traced */

    u8 unknown8[0xd0];
    void *unknownd8;
};

int FUN_00be1c30(Object00be5610 *self, void *value); /* derived name */

int FUN_00be5610(Object00be5610 *self) /* derived name */
{
    if (self->unknownd8 == 0) {
        return 0;
    }
    return FUN_00be1c30(self, self->slot5());
}
