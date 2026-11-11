/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 3 of the vtable at 0x16bc108 (its pointer at
 * 0x16bc130): passes the object, its argument and what the object's slot 8
 * returns to FUN_00db3930, as a tail call. Class and method unknown. */
class Object013c8400 /* derived name */
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
    virtual void *slot8(); /* derived name */
};

void FUN_00db3930(Object013c8400 *self, void *argument, void *value); /* derived name */

void FUN_013c8400(Object013c8400 *self, void *argument) /* derived name */
{
    FUN_00db3930(self, argument, self->slot8());
}
