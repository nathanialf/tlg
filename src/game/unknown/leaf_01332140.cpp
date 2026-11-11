/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 10 of each object in the array of pointers at
 * +0x10 of the record the pointer at +0x28 of the object the pointer at
 * 0x57c9390 holds, counted by the unsigned int at +0x18 of that record (an
 * unsigned counter, the array's accessor taking an int index: sign-extended
 * each pass); slot 5 of
 * the vtable at 0x16c5f50 (its pointer at 0x16c5f88), one of the vtables whose
 * slot 0 is the destructor of Object013a6a50 (FUN_013a6a50), as
 * leaf_013320a0.cpp's. The object itself is not read. The elements' class and
 * the slot's return type are not traced. */
class Object013a6a50; /* derived name */

class Element01332140 /* derived name */
{
  public:
    virtual void slot0();  /* derived name; not traced */
    virtual void slot1();  /* derived name; not traced */
    virtual void slot2();  /* derived name; not traced */
    virtual void slot3();  /* derived name; not traced */
    virtual void slot4();  /* derived name; not traced */
    virtual void slot5();  /* derived name; not traced */
    virtual void slot6();  /* derived name; not traced */
    virtual void slot7();  /* derived name; not traced */
    virtual void slot8();  /* derived name; not traced */
    virtual void slot9();  /* derived name; not traced */
    virtual void slot10(); /* derived name; not traced */
};

struct Array01332140 /* derived name: the array at +0x10 and its count */
{
    Element01332140 **data; /* derived name */
    unsigned count;         /* derived name */

    Element01332140 *operator[](int index) const
    {
        return data[index];
    }
};

struct Member057c9390_28 /* derived name */
{
    u8 unknown0[0x10];
    Array01332140 unknown10; /* +0x10 */
};

struct Object057c9390 /* derived name */
{
    u8 unknown0[0x28];
    Member057c9390_28 *unknown28; /* +0x28 */
};

extern Object057c9390 *D_57c9390;

void FUN_01332140(Object013a6a50 *) /* derived name */
{
    Member057c9390_28 *list = D_57c9390->unknown28;
    for (unsigned i = 0; i < list->unknown10.count; i++)
        list->unknown10[i]->slot10();
}
