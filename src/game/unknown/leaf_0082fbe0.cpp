/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: when the int at +0x30 is set, calls slot 9 of the object's
 * vtable with the float its argument points to; returns 1 either way. Its
 * address is taken by FUN_0133f330. The slots before 9 and the return types
 * are not traced. Class and method unknown. */
class Object0082fbe0 /* derived name */
{
  public:
    virtual void slot0();            /* derived name; not traced */
    virtual void slot1();            /* derived name; not traced */
    virtual void slot2();            /* derived name; not traced */
    virtual void slot3();            /* derived name; not traced */
    virtual void slot4();            /* derived name; not traced */
    virtual void slot5();            /* derived name; not traced */
    virtual void slot6();            /* derived name; not traced */
    virtual void slot7();            /* derived name; not traced */
    virtual void slot8();            /* derived name; not traced */
    virtual void slot9(float value); /* derived name */

    u8 unknown8[0x28];
    int unknown30;
};

int FUN_0082fbe0(Object0082fbe0 *self, const float *value) /* derived name */
{
    if (self->unknown30) {
        self->slot9(*value);
    }
    return 1;
}
