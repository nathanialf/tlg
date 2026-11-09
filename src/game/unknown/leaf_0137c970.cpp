/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls its own slot 10 through the vtable when the int at
 * +0x4cc is zero, as a tail call; slot 30 of the vtable at 0x16b0d90 (its
 * pointer at 0x16b0e90), the vtable stored by FUN_0137c320. Class and method
 * unknown. */
class Object0137c970 /* derived name */
{
  public:
    virtual void slot0();  /* derived name; not traced */
    virtual void slot1();  /* derived name; not traced */
    virtual void slot2();  /* derived name; not traced */
    virtual void slot3();  /* derived name; not traced */
    virtual void slot4();  /* derived name; not traced */
    virtual void slot5();  /* derived name; not traced */
    virtual void slot6();  /* derived name; not traced */
    virtual void slot7();  /* derived name; not traced */
    virtual void slot8();  /* derived name; not traced */
    virtual void slot9();  /* derived name; not traced */
    virtual void slot10(); /* derived name; not traced */

    u8 unknown8[0x4cc - 8];
    int unknown4cc;
};

void FUN_0137c970(Object0137c970 *self) /* derived name */
{
    if (!self->unknown4cc) {
        self->slot10();
    }
}
