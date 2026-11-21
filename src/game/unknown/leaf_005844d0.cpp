/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a node with a list of nodes, the array at +0x30 and its
 * count at +0x38 (FUN_005844d0). */
struct NodeArray5844d0 /* derived name */
{
    u8 unknown0[0x30];
    Node583950 **nodes; /* +0x30 */
    unsigned count;     /* +0x38 */
};

/* derived names: a handler whose address FUN_005269a0 takes (lea at
 * 0x527cf2): FUN_005839e0's copy of the state byte from the owner's first
 * list to its second, then each node of its list dispatched. Returns 0.
 * Handler unknown. */
int FUN_005844d0(FrameOwner583950 *self, NodeArray5844d0 *node) /* derived name */
{
    char *from = self->cursor.select(node) ? self->cursor.value() : 0;
    char *to = self->cursor190.select(node) ? self->cursor190.value() : 0;
    if (from && to) {
        const u8 *state = self->selectState(node);
        *self->cursor190.selectState(node) = state ? *state : 0;
        Node583950 **end = node->nodes + node->count;
        for (Node583950 **child = node->nodes; child != end; ++child)
            self->dispatch(*child);
    }
    return 0;
}
