/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 4 of the object the pointer at +0x8 holds with the
 * string "..." (0x15bd4f4) as a tail call. The member's class and the return
 * type are not traced; slot 3 of the vtable at 0x16a9dc8 (its pointer at
 * 0x16a9df0), the vtable stored by FUN_0047a6e0 FUN_0047dd70 FUN_0047de60 |
 * home vm-core.cpp. Class and method unknown. */
class Member0047e2f0 /* derived name */
{
  public:
    virtual void slot0();                 /* derived name; not traced */
    virtual void slot1();                 /* derived name; not traced */
    virtual void slot2();                 /* derived name; not traced */
    virtual void slot3();                 /* derived name; not traced */
    virtual void slot4(const char *text); /* derived name; not traced */
};

struct Object0047e2f0 { /* derived name */
    u8 unknown0[8];
    Member0047e2f0 *unknown8;
};

void FUN_0047e2f0(Object0047e2f0 *self) /* derived name */
{
    self->unknown8->slot4("...");
}
