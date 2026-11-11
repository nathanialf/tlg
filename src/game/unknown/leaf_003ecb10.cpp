/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 8 of the vtable at 0x16a9328 (stored by FUN_003ebf60;
 * its address at 0x16a9378): calls slot 8 of each of the object's children with its
 * argument (the pointers at +0x28, counted by the unsigned int at +0x30, an
 * array indexed by int: the index sign-extended in the loop), as
 * leaf_003ecb60.cpp's slot 9 does, and returns 1. The children's answers
 * and the argument's type are not traced. Class and method unknown. */
class Child003ecb10 /* derived name */
{
  public:
    virtual void slot0();              /* derived name; not traced */
    virtual void slot1();              /* derived name; not traced */
    virtual void slot2();              /* derived name; not traced */
    virtual void slot3();              /* derived name; not traced */
    virtual void slot4();              /* derived name; not traced */
    virtual void slot5();              /* derived name; not traced */
    virtual void slot6();              /* derived name; not traced */
    virtual void slot7();              /* derived name; not traced */
    virtual int slot8(void *argument); /* derived name */
};

struct ChildArray003ecb10 { /* derived name */
    Child003ecb10 **data;   /* derived name */
    u32 count;              /* derived name */

    u32 size() const
    {
        return count;
    }

    Child003ecb10 *operator[](int index) const
    {
        return data[index];
    }
};

struct Object003ecb10 { /* derived name */
    u8 unknown0[0x28];
    ChildArray003ecb10 unknown28; /* +0x28: the children */
};

int FUN_003ecb10(Object003ecb10 *self, void *argument) /* derived name */
{
    for (u32 i = 0; i < self->unknown28.size(); i++)
        self->unknown28[i]->slot8(argument);
    return 1;
}
