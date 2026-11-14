/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_math.h"

/* derived names: returns by value (the hidden result pointer passed on) what
 * slot 1 or, when the int at 0x20 is 0, slot 2 of the object the pointer at
 * +0x10 holds returns for the int at +0x8; slot 6 of the vtable at 0x16d3c70
 * (its pointer at 0x16d3cb0), stored by FUN_00f7baf0, its slot 0 the empty
 * method FUN_001af750. The value's type is taken as Float4A (returned through
 * the hidden pointer); the class is not traced. */
class Source013d88e0 /* derived name */
{
  public:
    virtual void slot0();             /* derived name; not traced */
    virtual Float4A slot1(int value); /* derived name; not traced */
    virtual Float4A slot2(int value); /* derived name; not traced */
};

struct Object013d88e0 { /* derived name */
    u8 unknown0[0x8];
    int unknown8;
    u8 unknownc[0x4];
    Source013d88e0 *unknown10;
    u8 unknown18[0x8];
    int unknown20;
};

Float4A FUN_013d88e0(const Object013d88e0 *self) /* derived name */
{
    if (self->unknown20)
        return self->unknown10->slot1(self->unknown8);
    return self->unknown10->slot2(self->unknown8);
}
