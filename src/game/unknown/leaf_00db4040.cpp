/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 3 of the vtable at 0x16bc0a0 (its pointer at
 * 0x16bc0c8): calls the object's slot 2 with its argument and what its slot 8
 * returns, a tail call (slot 2's address loaded before slot 8 is called). The
 * class, the argument's type and the return types are not traced. */
class Object016bc0a0 /* derived name */
{
  public:
    virtual void slot0();                            /* derived name; not traced */
    virtual void slot1();                            /* derived name; not traced */
    virtual void slot2(void *argument, void *value); /* derived name; not traced */
    virtual void slot3();                            /* derived name; not traced */
    virtual void slot4();                            /* derived name; not traced */
    virtual void slot5();                            /* derived name; not traced */
    virtual void slot6();                            /* derived name; not traced */
    virtual void slot7();                            /* derived name; not traced */
    virtual void *slot8();                           /* derived name; not traced */
};

void FUN_00db4040(Object016bc0a0 *self, void *argument) /* derived name */
{
    self->slot2(argument, self->slot8());
}
