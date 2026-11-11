/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 5 of the vtables at 0x16a92c8 (stored by FUN_003ebdd0)
 * and 0x16a9328 (stored by FUN_003ebf60), one body each (0x3ec770, 0x3eca30):
 * calls slot 5 of each of the object's children (the pointers at +0x28,
 * counted by the unsigned int at +0x30, an array indexed by int: the index
 * sign-extended in the loop). The types are not traced. Class and method
 * unknown. */
class Child003eca30 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name */
};

struct ChildArray003eca30 { /* derived name */
    Child003eca30 **data;   /* derived name */
    u32 count;              /* derived name */

    u32 size() const
    {
        return count;
    }

    Child003eca30 *operator[](int index) const
    {
        return data[index];
    }
};

struct Object003eca30 { /* derived name */
    u8 unknown0[0x28];
    ChildArray003eca30 unknown28; /* +0x28: the children */
};

void FUN_003eca30(Object003eca30 *self) /* derived name */
{
    for (u32 i = 0; i < self->unknown28.size(); i++)
        self->unknown28[i]->slot5();
}
