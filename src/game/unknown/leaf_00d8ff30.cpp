/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback (its address taken by FUN_00d8f280): calls its own
 * slot 9 when the int at +0x30 is set, and returns 1. The slot's return type
 * is not traced. */
class Object00d8ff30 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual void slot7(); /* derived name; not traced */
    virtual void slot8(); /* derived name; not traced */
    virtual void slot9(); /* derived name; not traced */
    u8 unknown8[0x30 - 8];
    int unknown30;
};

int FUN_00d8ff30(Object00d8ff30 *self) /* derived name */
{
    if (self->unknown30) {
        self->slot9();
    }
    return 1;
}
