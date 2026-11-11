/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16a7a28 (+0x40 from the vtable stored at
 * 0x16a79e8, slot 6): when the int at +0x6c is set, calls the object's slot 10
 * with its argument and zeroes the int; then passes the object and the
 * argument to FUN_00ab9730, a tail call (most likely the base class's slot 6).
 * The classes and the return types are not traced. */
struct Argument00296750; /* derived name */

class Object00296750 /* derived name */
{
  public:
    virtual void slot0();                            /* derived name; not traced */
    virtual void slot1();                            /* derived name; not traced */
    virtual void slot2();                            /* derived name; not traced */
    virtual void slot3();                            /* derived name; not traced */
    virtual void slot4();                            /* derived name; not traced */
    virtual void slot5();                            /* derived name; not traced */
    virtual void slot6();                            /* derived name; not traced */
    virtual void slot7();                            /* derived name; not traced */
    virtual void slot8();                            /* derived name; not traced */
    virtual void slot9();                            /* derived name; not traced */
    virtual void slot10(Argument00296750 *argument); /* derived name; not traced */

    u8 unknown8[0x64];
    int unknown6c;
};

void FUN_00ab9730(Object00296750 *self, Argument00296750 *argument); /* derived name */

void FUN_00296750(Object00296750 *self, Argument00296750 *argument) /* derived name */
{
    if (self->unknown6c != 0) {
        self->slot10(argument);
        self->unknown6c = 0;
    }
    FUN_00ab9730(self, argument);
}
