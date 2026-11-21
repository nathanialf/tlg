/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a node holding a node at +0x28 and a list of nodes, the
 * array at +0x30 and its count at +0x38 (FUN_00584ba0). */
struct NodeArray584ba0 /* derived name */
{
    u8 unknown0[0x28];
    Node583950 *child;  /* +0x28 */
    Node583950 **nodes; /* +0x30 */
    unsigned count;     /* +0x38 */
};

/* derived names: a handler whose address FUN_005269a0 takes (lea at
 * 0x527c18): FUN_005839e0's copy of the state byte from the owner's first
 * list to its second, with the node's int value copied after it, then the
 * node at +0x28 and each node of its list dispatched. Returns 0. Handler
 * unknown. */
int FUN_00584ba0(FrameOwner583950 *self, NodeArray584ba0 *node) /* derived name */
{
    int *from = self->cursor.select(node) ? reinterpret_cast<int *>(self->cursor.value()) : 0;
    int *to = self->cursor190.select(node) ? reinterpret_cast<int *>(self->cursor190.value()) : 0;
    if (from && to) {
        const u8 *state = self->selectState(node);
        *self->cursor190.selectState(node) = state ? *state : 0;
        *to = *from;
        self->dispatch(node->child);
        Node583950 **end = node->nodes + node->count;
        for (Node583950 **child = node->nodes; child != end; ++child)
            self->dispatch(*child);
    }
    return 0;
}
