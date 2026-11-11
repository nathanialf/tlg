/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls the object's slot 6 with whether the value is 0, then
 * its slot 5, and stores the value at +0x200; slot 8 of the vtable at
 * 0x16b9cb0 (its pointer at 0x16b9d00), stored by FUN_001afd70. The slots'
 * return types are not traced. */
class Object00cffcc0 /* derived name */
{
  public:
    virtual void slot0();           /* derived name; not traced */
    virtual void slot1();           /* derived name; not traced */
    virtual void slot2();           /* derived name; not traced */
    virtual void slot3();           /* derived name; not traced */
    virtual void slot4();           /* derived name; not traced */
    virtual void slot5();           /* derived name; not traced */
    virtual void slot6(bool value); /* derived name; not traced */

    u8 unknown8[0x1f8];
    int unknown200;
};

void FUN_00cffcc0(Object00cffcc0 *self, int value) /* derived name */
{
    self->slot6(value == 0);
    self->slot5();
    self->unknown200 = value;
}
