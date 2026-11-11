/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears bit 4 of the flags byte at +0x24 of a node and of every
 * node below it, recursively through the children (the pointers at +0x40,
 * counted by the unsigned int at +0x48, an array indexed by int: the index
 * sign-extended in the loop); nothing for a null node. FUN_002a85d0 clears,
 * FUN_002a8610 sets. The node's type is not traced. */
struct Node002a85d0; /* derived name */

struct NodeArray002a85d0 { /* derived name */
    Node002a85d0 **data;   /* derived name */
    u32 count;             /* derived name */

    u32 size() const
    {
        return count;
    }

    Node002a85d0 *operator[](int index) const
    {
        return data[index];
    }
};

struct Node002a85d0 { /* derived name */
    u8 unknown0[0x24];
    u8 unknown24; /* +0x24: flags, bit 4 */
    u8 unknown25[0x1b];
    NodeArray002a85d0 unknown40; /* +0x40: the children */
};

void FUN_002a85d0(Node002a85d0 *self) /* derived name */
{
    if (!self)
        return;
    self->unknown24 &= ~0x10;
    for (u32 i = 0; i < self->unknown40.size(); i++)
        FUN_002a85d0(self->unknown40[i]);
}
