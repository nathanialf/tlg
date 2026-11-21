/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_math.h"

/* derived names: a node with a list of nodes, the array at +0x28 and its
 * count at +0x30 (FUN_00588640). */
struct NodeArray588640 /* derived name */
{
    u8 unknown0[0x28];
    Node583950 **nodes; /* +0x28 */
    unsigned count;     /* +0x30 */
};

/* derived names: a handler whose address FUN_005269a0 takes (lea at
 * 0x527c5f): FUN_005839e0's copy of the state byte from the owner's first
 * list to its second, with the node's value of four floats copied after it
 * (one 16-byte move), then each node of its list dispatched. Returns 0.
 * Handler unknown. */
int FUN_00588640(FrameOwner583950 *self, NodeArray588640 *node) /* derived name */
{
    Float4Data *from =
        self->cursor.select(node) ? reinterpret_cast<Float4Data *>(self->cursor.value()) : 0;
    Float4Data *to =
        self->cursor190.select(node) ? reinterpret_cast<Float4Data *>(self->cursor190.value()) : 0;
    if (from && to) {
        const u8 *state = self->selectState(node);
        *self->cursor190.selectState(node) = state ? *state : 0;
        *to = *from;
        Node583950 **end = node->nodes + node->count;
        for (Node583950 **child = node->nodes; child != end; ++child)
            self->dispatch(*child);
    }
    return 0;
}
