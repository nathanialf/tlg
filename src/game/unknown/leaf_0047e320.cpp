/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 3 of the object the pointer at +0x8 holds with
 * 0x3d (61) as a tail call. The member's class, the argument's type and the
 * return type are not traced; slot 5 of the vtable at 0x16a9dc8 (its pointer
 * at 0x16a9e00), the vtable stored by FUN_0047a6e0 FUN_0047dd70 FUN_0047de60 |
 * home vm-core.cpp. Class and method unknown. */
class Member0047e320 /* derived name */
{
  public:
    virtual void slot0();          /* derived name; not traced */
    virtual void slot1();          /* derived name; not traced */
    virtual void slot2();          /* derived name; not traced */
    virtual void slot3(int value); /* derived name; not traced */
};

struct Object0047e320 { /* derived name */
    u8 unknown0[8];
    Member0047e320 *unknown8;
};

void FUN_0047e320(Object0047e320 *self) /* derived name */
{
    self->unknown8->slot3(0x3d);
}
