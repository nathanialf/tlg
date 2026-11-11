/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 9 of the vtable at 0x16a9328 (stored by FUN_003ebf60;
 * its address at 0x16a9380): calls slot 9 of each of the object's children
 * with its argument (the pointers at +0x28, counted by the unsigned int at
 * +0x30, an array indexed by int: the index sign-extended in the loop), as
 * slot 5, FUN_003eca30, calls their slot 5. The argument's type is not
 * traced. Class and method unknown. */
class Child003ecb60 /* derived name */
{
  public:
    virtual void slot0();               /* derived name; not traced */
    virtual void slot1();               /* derived name; not traced */
    virtual void slot2();               /* derived name; not traced */
    virtual void slot3();               /* derived name; not traced */
    virtual void slot4();               /* derived name; not traced */
    virtual void slot5();               /* derived name; not traced */
    virtual void slot6();               /* derived name; not traced */
    virtual void slot7();               /* derived name; not traced */
    virtual void slot8();               /* derived name; not traced */
    virtual void slot9(void *argument); /* derived name */
};

struct ChildArray003ecb60 { /* derived name */
    Child003ecb60 **data;   /* derived name */
    u32 count;              /* derived name */

    u32 size() const
    {
        return count;
    }

    Child003ecb60 *operator[](int index) const
    {
        return data[index];
    }
};

struct Object003ecb60 { /* derived name */
    u8 unknown0[0x28];
    ChildArray003ecb60 unknown28; /* +0x28: the children */
};

void FUN_003ecb60(Object003ecb60 *self, void *argument) /* derived name */
{
    for (u32 i = 0; i < self->unknown28.size(); i++)
        self->unknown28[i]->slot9(argument);
}
