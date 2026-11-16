/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the node of a tree whose id (+0x210) is the id the owner's
 * table at +0x60 holds at an index, the node itself first, then each child
 * (+0x40, count +0x48) in turn, depth first; null when none is. Called by
 * FUN_00b4c160 (0xb4c467) and by itself. The classes are not traced. */
struct Node00b4c4b0 { /* derived name */
    u8 unknown0[0x40];
    Node00b4c4b0 **children; /* +0x40, derived name */
    unsigned childCount;     /* +0x48, derived name */
    u8 unknown4c[0x210 - 0x4c];
    int id; /* +0x210, derived name */

    /* a child at a signed index (`movsxd` under the unsigned count) */
    Node00b4c4b0 *childAt(int index) const /* derived name */
    {
        return children[index];
    }
};

struct Object00b4c4b0 { /* derived name */
    u8 unknown0[0x60];
    int *ids; /* +0x60, derived name */
};

// NONMATCHING: register assignment only: the node's id is loaded into esi (the index's register,
// free after its copy to r14d), the table into rcx and the index into rax; the build takes eax,
// rsi and rcx (the compare written the other way gives rcx and rax with the id loaded last)
Node00b4c4b0 *FUN_00b4c4b0(Object00b4c4b0 *self, int index, Node00b4c4b0 *node) /* derived name */
{
    if (node->id == self->ids[index])
        return node;
    for (unsigned i = 0; i < node->childCount; i++) {
        if (Node00b4c4b0 *found = FUN_00b4c4b0(self, index, node->childAt(i)))
            return found;
    }
    return 0;
}
