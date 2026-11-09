/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 10 of the object at 0x258 with no further argument
 * traced, as a tail call; slot 31 of the vtable at 0x16b0d90 (its pointer at
 * 0x16b0e98), the vtable stored by FUN_0137c320. The target's class and the
 * return type are not traced. Class and method unknown. */
class Target00925760 /* derived name */
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
    virtual void slot10(); /* derived name; parameters not traced */
};

struct Object0137c320 { /* derived name */
    u8 unknown0[0x258];
    Target00925760 *unknown258;
};

void FUN_00925760(Object0137c320 *self) /* derived name */
{
    self->unknown258->slot10();
}
