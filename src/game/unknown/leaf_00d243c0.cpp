/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 7 of the object at +0xa0, when there is one,
 * with the object itself, as a tail call; slot 22 of the vtable at 0x16ae890
 * and slot 8 of 0x16b83f0, 0x16ba190, 0x16ba730 and two more (six slots).
 * Class and method unknown. */
struct Object00d243c0; /* derived name */

class Target00d243c0 /* derived name */
{
  public:
    virtual void slot0();                      /* derived name; not traced */
    virtual void slot1();                      /* derived name; not traced */
    virtual void slot2();                      /* derived name; not traced */
    virtual void slot3();                      /* derived name; not traced */
    virtual void slot4();                      /* derived name; not traced */
    virtual void slot5();                      /* derived name; not traced */
    virtual void slot6();                      /* derived name; not traced */
    virtual void slot7(Object00d243c0 *owner); /* derived name */
};

struct Object00d243c0 { /* derived name */
    u8 unknown0[0xa0];
    Target00d243c0 *unknowna0;
};

void FUN_00d243c0(Object00d243c0 *self) /* derived name */
{
    if (self->unknowna0) {
        self->unknowna0->slot7(self);
    }
}
