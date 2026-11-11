/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 6 of the vtable at 0x16a9328 (stored by FUN_003ebf60;
 * its address at 0x16a9368): calls slot 6 of each of the object's children with its
 * argument (the pointers at +0x28, counted by the unsigned int at +0x30, an
 * array indexed by int: the index sign-extended in the loop), as
 * leaf_003ecb60.cpp's slot 9 does, and returns 1. The children's answers
 * and the argument's type are not traced. Class and method unknown. */
class Child003eca70 /* derived name */
{
  public:
    virtual void slot0();              /* derived name; not traced */
    virtual void slot1();              /* derived name; not traced */
    virtual void slot2();              /* derived name; not traced */
    virtual void slot3();              /* derived name; not traced */
    virtual void slot4();              /* derived name; not traced */
    virtual void slot5();              /* derived name; not traced */
    virtual int slot6(void *argument); /* derived name */
};

struct ChildArray003eca70 { /* derived name */
    Child003eca70 **data;   /* derived name */
    u32 count;              /* derived name */

    u32 size() const
    {
        return count;
    }

    Child003eca70 *operator[](int index) const
    {
        return data[index];
    }
};

struct Object003eca70 { /* derived name */
    u8 unknown0[0x28];
    ChildArray003eca70 unknown28; /* +0x28: the children */
};

int FUN_003eca70(Object003eca70 *self, void *argument) /* derived name */
{
    for (u32 i = 0; i < self->unknown28.size(); i++)
        self->unknown28[i]->slot6(argument);
    return 1;
}
