/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 9 of the vtable at 0x16aac80 (stored by FUN_00506af0
 * FUN_00506ef0): calls the object's own slot 23 with 0, then, when the
 * pointer at +0xc8 of the object at 0x57c9390 is set, FUN_00507f80 with it
 * and the object, as a tail call. The types are not traced. Class and method
 * unknown. */
struct Target00507f80; /* derived name */

class Object00506eb0 /* derived name */
{
  public:
    virtual void slot0();           /* derived name; not traced */
    virtual void slot1();           /* derived name; not traced */
    virtual void slot2();           /* derived name; not traced */
    virtual void slot3();           /* derived name; not traced */
    virtual void slot4();           /* derived name; not traced */
    virtual void slot5();           /* derived name; not traced */
    virtual void slot6();           /* derived name; not traced */
    virtual void slot7();           /* derived name; not traced */
    virtual void slot8();           /* derived name; not traced */
    virtual void slot9();           /* derived name; not traced */
    virtual void slot10();          /* derived name; not traced */
    virtual void slot11();          /* derived name; not traced */
    virtual void slot12();          /* derived name; not traced */
    virtual void slot13();          /* derived name; not traced */
    virtual void slot14();          /* derived name; not traced */
    virtual void slot15();          /* derived name; not traced */
    virtual void slot16();          /* derived name; not traced */
    virtual void slot17();          /* derived name; not traced */
    virtual void slot18();          /* derived name; not traced */
    virtual void slot19();          /* derived name; not traced */
    virtual void slot20();          /* derived name; not traced */
    virtual void slot21();          /* derived name; not traced */
    virtual void slot22();          /* derived name; not traced */
    virtual void slot23(int value); /* derived name */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0xc8];
    Target00507f80 *unknownc8; /* +0xc8 */
};

extern Object057c9390 *D_57c9390;

void FUN_00507f80(Target00507f80 *target, Object00506eb0 *object); /* derived name */

void FUN_00506eb0(Object00506eb0 *self) /* derived name */
{
    self->slot23(0);
    if (D_57c9390->unknownc8)
        FUN_00507f80(D_57c9390->unknownc8, self);
}
