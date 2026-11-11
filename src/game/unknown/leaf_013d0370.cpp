/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_math.h"

/* derived names: returns by value (the hidden result pointer passed on) what
 * slot 1 or, when the int at 0x28 is 0, slot 2 of the object the pointer at
 * +0x10 holds returns for the int at +0x8; slot 6 of the vtable at 0x16d39a8
 * (its pointer at 0x16d39e8), stored by FUN_00f4de30, its slot 0 the empty
 * method FUN_001af750. The value's type is taken as Float4A (returned through
 * the hidden pointer); the class is not traced. */
class Source013d0370 /* derived name */
{
  public:
    virtual void slot0();             /* derived name; not traced */
    virtual Float4A slot1(int value); /* derived name; not traced */
    virtual Float4A slot2(int value); /* derived name; not traced */
};

struct Object013d0370 { /* derived name */
    u8 unknown0[0x8];
    int unknown8;
    u8 unknownc[0x4];
    Source013d0370 *unknown10;
    u8 unknown18[0x10];
    int unknown28;
};

// NONMATCHING: the base passes the result pointer on in rdi as it came (only copying it to rbx for
// the return), the compile copies rbx back to rdi before each call; every instruction else equal
// (greedy's or the coalescer's choice)
Float4A FUN_013d0370(const Object013d0370 *self) /* derived name */
{
    if (self->unknown28)
        return self->unknown10->slot1(self->unknown8);
    return self->unknown10->slot2(self->unknown8);
}
