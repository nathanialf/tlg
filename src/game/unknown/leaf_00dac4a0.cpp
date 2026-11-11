/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 59 of the vtable at 0x16bb0c0 (the vtable of
 * FUN_00daf400's object): the int slot 4 of the object at +0x18 returns,
 * stored at +0xf64 of the record at +0x7dc8. The types are not traced. Class
 * and method unknown. */
class Source00dac4a0 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual int slot4();  /* derived name; not traced */
};

struct Record00dac4a0 { /* derived name */
    u8 unknown0[0xf64];
    int unknownf64;
};

struct Object00dac4a0 { /* derived name */
    u8 unknown0[0x18];
    Source00dac4a0 *unknown18;
    u8 unknown20[0x7da8];
    Record00dac4a0 *unknown7dc8;
};

void FUN_00dac4a0(Object00dac4a0 *self) /* derived name */
{
    int value = self->unknown18->slot4();
    self->unknown7dc8->unknownf64 = value;
}
