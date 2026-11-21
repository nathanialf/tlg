/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the int at +0x20 of the object joined (or) with what slot 6
 * of each of its children (the counted references at +0x58, their count at
 * +0x60 read once) returns for the argument; each child is held by a
 * reference of its own during its call. The classes and the slot's meaning
 * are not traced. */
class Child0096a170 : public Object016b9108 /* derived name */
{
  public:
    virtual void slot5();            /* derived name */
    virtual int slot6(int argument); /* derived name */
};

struct Object0096a170 { /* derived name */
    u8 unknown0[0x20];
    int unknown20; /* +0x20 */
    u8 unknown24[0x34];
    Ref00503fb0<Child0096a170> *children; /* +0x58 */
    unsigned childCount;                  /* +0x60 */

    const Ref00503fb0<Child0096a170> &childAt(int index) const /* derived name */
    {
        return children[index];
    }
};

int FUN_0096a170(Object0096a170 *self, int argument) /* derived name */
{
    unsigned count = self->childCount;
    int result = self->unknown20;
    for (unsigned i = 0; i < count; ++i) {
        Ref00503fb0<Child0096a170> child(self->childAt(i));
        if (child.get())
            result |= child.get()->slot6(argument);
    }
    return result;
}

/* derived names: slot 5 of the object's class: bits 4 and 5 of the int at
 * +0x20 cleared, then slot 5 of each child, each held by a reference of its
 * own during its call. */
void FUN_0096a290(Object0096a170 *self) /* derived name */
{
    self->unknown20 &= ~0x30;
    unsigned count = self->childCount;
    for (unsigned i = 0; i < count; ++i) {
        Ref00503fb0<Child0096a170> child(self->childAt(i));
        if (child.get())
            child.get()->slot5();
    }
}
