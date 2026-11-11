/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16b7a38 (+0x388 in the vtable of
 * Object00bc3b10, config/vtables.derived.base.txt): as FUN_00be5610, when the
 * pointer at +0xd8 is set and differs from the one at +0x98, returns what
 * FUN_00be1c30 returns for the object and what its slot 5 returns, a tail
 * call; else 0. The class and the types are not traced. */
class Object00be4a10 /* derived name */
{
  public:
    virtual void slot0();  /* derived name; not traced */
    virtual void slot1();  /* derived name; not traced */
    virtual void slot2();  /* derived name; not traced */
    virtual void slot3();  /* derived name; not traced */
    virtual void slot4();  /* derived name; not traced */
    virtual void *slot5(); /* derived name; not traced */

    u8 unknown8[0x90];
    void *unknown98;
    u8 unknownA0[0x38];
    void *unknownd8;
};

int FUN_00be1c30(Object00be4a10 *self, void *value); /* derived name */

int FUN_00be4a10(Object00be4a10 *self) /* derived name */
{
    if (self->unknownd8 == 0 || self->unknownd8 == self->unknown98) {
        return 0;
    }
    return FUN_00be1c30(self, self->slot5());
}
