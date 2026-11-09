/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores its int argument at +0x158, then calls its own slot 19
 * (0x1af750, an empty body, in these vtables) through the vtable as a tail
 * call; slot 17 of the vtable at 0x16ba8e0 (its pointer at 0x16ba978), the
 * vtable stored by FUN_00d5f7d0 FUN_013b9d70; slot 17 of the vtable at
 * 0x16be9a8 (its pointer at 0x16bea40), the vtable stored by FUN_00eb3c90
 * FUN_00eb3fb0. Class and method unknown. */
class Object013ba200 /* derived name */
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
    virtual void slot11(); /* derived name; not traced */
    virtual void slot12(); /* derived name; not traced */
    virtual void slot13(); /* derived name; not traced */
    virtual void slot14(); /* derived name; not traced */
    virtual void slot15(); /* derived name; not traced */
    virtual void slot16(); /* derived name; not traced */
    virtual void slot17(); /* derived name; not traced */
    virtual void slot18(); /* derived name; not traced */
    virtual void slot19(); /* derived name; not traced */

    u8 unknown8[0x158 - 8];
    int unknown158;
};

void FUN_013ba200(Object013ba200 *self, int value) /* derived name */
{
    self->unknown158 = value;
    self->slot19();
}
