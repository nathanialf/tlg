/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: a node taken out of its parent's children. With a parent
 * at +0x38 the node holds a reference to itself for the length of the work
 * (`lock inc dword [r12]` at 0xc57149 with no null test, the drop at
 * 0xc57198), FUN_00c56780 runs over it, the parent's flag 2 at +0x20 is
 * set, FUN_01351240 takes the node's index (+0x218) out of the parent's
 * children and, when it moved another child there, that child's index is
 * set; then the node's parent is cleared and its index made -1. The class
 * is a node's (the parent at +0x38, the children at +0x40); its other
 * members are not traced. */
struct Node00c57120 : Node00503fb0 { /* derived name */
    u8 unknown64[0x1b4];
    int index; /* +0x218 */
};

void FUN_00c56780(Node00c57120 *node);                             /* derived name */
int FUN_01351240(Ref00503fb0<Node00503fb0> **children, int index); /* derived name */

void FUN_00c57120(Node00c57120 *self) /* derived name */
{
    Node00503fb0 *parent = self->parent;
    if (parent) {
        addReference(self);
        FUN_00c56780(self);
        parent->flags20 |= 2;
        int index = self->index;
        if (FUN_01351240(&parent->children, index))
            static_cast<Node00c57120 *>(parent->children[index].get())->index = index;
        self->parent = 0;
        self->index = -1;
        dropReference(self);
    }
}
