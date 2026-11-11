/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 6 of the vtable at 0x16a9dc8 (its pointer at
 * 0x16a9e08), the vtable stored by FUN_0047a6e0 FUN_0047dd70 FUN_0047de60 |
 * home vm-core.cpp: writes ',' and a line break ("\r\n") through slot 3 of
 * the object the pointer at +0x8 holds, then one tab for each level of the
 * int at +0x10 (read again after each write), as FUN_0047e320 writes '='.
 * Class and method unknown. */
class Member0047e320 /* derived name */
{
  public:
    virtual void slot0();          /* derived name; not traced */
    virtual void slot1();          /* derived name; not traced */
    virtual void slot2();          /* derived name; not traced */
    virtual void slot3(int value); /* derived name; not traced */
};

struct Object0047e320 { /* derived name, as FUN_0047e320 names it */
    u8 unknown0[8];
    Member0047e320 *unknown8; /* +0x8 */
    int unknown10;            /* +0x10: the depth */
};

void FUN_0047e340(Object0047e320 *self) /* derived name */
{
    self->unknown8->slot3(',');
    self->unknown8->slot3('\r');
    self->unknown8->slot3('\n');
    for (int i = 0; i < self->unknown10; ++i)
        self->unknown8->slot3('\t');
}
