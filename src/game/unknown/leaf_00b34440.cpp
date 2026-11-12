/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the pointer the array at +0x40 of the object holds at
 * one past the index slot 10 of the object the pointer at 0x5989c08 returns
 * (an int, sign-extended); slot 5 of the vtable at 0x16b55a0 (its pointer at
 * 0x16b55d8), stored by FUN_00908b80, FUN_00b32dd0 and the destructors
 * FUN_00b32f80 and FUN_00b32fc0. FUN_00b34440 and FUN_00b34470 are equal. The
 * classes and the array's element type are not traced. */
class Object05989c08 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual void slot7(); /* derived name; not traced */
    virtual void slot8(); /* derived name; not traced */
    virtual void slot9(); /* derived name; not traced */
    virtual int slot10(); /* derived name; not traced */
};

extern Object05989c08 *D_5989c08;

struct Object00b34440 { /* derived name */
    u8 unknown0[0x40];
    void *unknown40[1];
};

void *FUN_00b34440(const Object00b34440 *self) /* derived name */
{
    return self->unknown40[D_5989c08->slot10() + 1];
}
