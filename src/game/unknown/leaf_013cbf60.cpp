/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 2 of the vtable at 0x16d3308 (its pointer at
 * 0x16d3328): with a nonzero argument, returns what slot 4 of the object at
 * +0x8 gives for it, 32 and 1, as a tail call; else 0. Class and method
 * unknown. */
class Target013cbf60 /* derived name */
{
  public:
    virtual void slot0();                              /* derived name; not traced */
    virtual void slot1();                              /* derived name; not traced */
    virtual void slot2();                              /* derived name; not traced */
    virtual void slot3();                              /* derived name; not traced */
    virtual int slot4(int value, int size, int count); /* derived name */
};

struct Object013cbf60 { /* derived name */
    u8 unknown0[0x8];
    Target013cbf60 *unknown8;
};

int FUN_013cbf60(Object013cbf60 *self, int value) /* derived name */
{
    if (value) {
        return self->unknown8->slot4(value, 32, 1);
    }
    return 0;
}
