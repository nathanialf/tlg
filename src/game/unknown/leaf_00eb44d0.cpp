/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback FUN_00eb45d0 stores in its table (lea at
 * 0xeb470d), beside FUN_00eb4520: when the object the pointer at +0x28 of the
 * object the pointer at 0x5938c40 holds is not null, calls its slot 3 with
 * the callback's second argument and 4; a null result returns -0x42, else it
 * is stored through the third argument and 0 returned; -0x41 when the object
 * is null. The callback's first parameter is not read; its type, the member's
 * class and the slot's parameter types are not traced. */
class Member05938c40_28 /* derived name */
{
  public:
    virtual void slot0();                           /* derived name; not traced */
    virtual void slot1();                           /* derived name; not traced */
    virtual void slot2();                           /* derived name; not traced */
    virtual void *slot3(void *argument, int value); /* derived name; not traced */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x28];
    Member05938c40_28 *unknown28;
};

extern Object05938c40 *D_5938c40;

int FUN_00eb44d0(void *, void *argument, void **result) /* derived name */
{
    Member05938c40_28 *member = D_5938c40->unknown28;
    if (!member)
        return -0x41;
    void *value = member->slot3(argument, 4);
    if (!value)
        return -0x42;
    *result = value;
    return 0;
}
