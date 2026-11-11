/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 5 of the vtables at 0x16b5a40 (stored by FUN_00b3ec10)
 * and 0x16b5c48 (stored by FUN_00b404d0 and the destructor FUN_01397620),
 * neither named: clears bits 4 and 5 of the flags byte at +0x20, then calls
 * slot 5 of the objects the pointers at +0x58 and +0x60 hold, each when set
 * (the second as a tail call). FUN_00b40830, slot 1 of the secondary vtables
 * at 0x16b5ab8 and 0x16b5cc0, is the same body reached through the base at
 * +0x30. The targets' class and the meaning of the bits are not traced. */
class Target00b407f0 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name */
};

struct Object00b407f0 /* derived name */
{
    u8 unknown0[0x20];
    u8 unknown20; /* +0x20: flags */
    u8 unknown21[0x37];
    Target00b407f0 *unknown58; /* +0x58 */
    Target00b407f0 *unknown60; /* +0x60 */
};

void FUN_00b407f0(Object00b407f0 *self) /* derived name */
{
    self->unknown20 &= ~0x30;
    if (self->unknown58)
        self->unknown58->slot5();
    if (self->unknown60)
        self->unknown60->slot5();
}
