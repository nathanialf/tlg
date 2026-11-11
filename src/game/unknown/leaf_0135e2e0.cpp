/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: whether the object's slot 7 or, when that returns 0, its slot
 * 12 returns nonzero; slot 6 of the vtable at 0x16abb60 (its pointer at
 * 0x16abba0), stored by FUN_005b05b0 and FUN_005b14b0. The class's other slots
 * are not traced. */
class Object0135e2e0 /* derived name */
{
  public:
    virtual void slot0();  /* derived name; not traced */
    virtual void slot1();  /* derived name; not traced */
    virtual void slot2();  /* derived name; not traced */
    virtual void slot3();  /* derived name; not traced */
    virtual void slot4();  /* derived name; not traced */
    virtual void slot5();  /* derived name; not traced */
    virtual void slot6();  /* derived name; not traced */
    virtual int slot7();   /* derived name; not traced */
    virtual void slot8();  /* derived name; not traced */
    virtual void slot9();  /* derived name; not traced */
    virtual void slot10(); /* derived name; not traced */
    virtual void slot11(); /* derived name; not traced */
    virtual int slot12();  /* derived name; not traced */
};

int FUN_0135e2e0(Object0135e2e0 *self) /* derived name */
{
    return self->slot7() != 0 || self->slot12() != 0;
}
