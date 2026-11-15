/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the int at +0x20 of the object joined (or) with what slot 6
 * of the object at +0x40 returns for the argument without its bit 1 (asked
 * only when the bit is set and the object is there) and with what slot 6 of
 * each of its children (the counted references at +0x58, their count at
 * +0x60 read once) returns for the argument; each child is held by a
 * reference of its own during its call. FUN_0096a170 (leaf_0096a170.cpp) is
 * the same without the object at +0x40. The classes and the slot's meaning
 * are not traced. */
class Child00b3e130 /* derived name */
{
  public:
    virtual void unknown0();
    virtual void unknown1();
    virtual void destroy(); /* derived name; slot 2 */
    virtual void unknown3();
    virtual void unknown4();
    virtual void unknown5();
    virtual int slot6(int argument); /* derived name */

    int references; /* +0x8 */
};

struct Object00b3e130 { /* derived name */
    u8 unknown0[0x20];
    int unknown20; /* +0x20 */
    u8 unknown24[0x1c];
    Child00b3e130 *unknown40; /* +0x40 */
    u8 unknown48[0x10];
    Ref00503fb0<Child00b3e130> *children; /* +0x58 */
    unsigned childCount;                  /* +0x60 */

    const Ref00503fb0<Child00b3e130> &childAt(int index) const /* derived name */
    {
        return children[index];
    }
};

void FUN_00c14bc0(Child00b3e130 *child); /* derived name: releases it later */

int FUN_00b3e130(Object00b3e130 *self, int argument) /* derived name */
{
    int result = self->unknown20;
    if ((argument & 2) && self->unknown40)
        result |= self->unknown40->slot6(argument & ~2);
    unsigned count = self->childCount;
    for (unsigned i = 0; i < count; ++i) {
        Ref00503fb0<Child00b3e130> child(self->childAt(i));
        if (child.get())
            result |= child.get()->slot6(argument);
    }
    return result;
}
