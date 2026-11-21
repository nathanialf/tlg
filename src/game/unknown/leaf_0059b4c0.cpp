/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: the 24-byte value FUN_0059b4c0 copies between the
 * owner's two lists: two values of three floats. */
struct Value59b4c0 /* derived name */
{
    Vector583950 unknown0;
    Vector583950 unknownc; /* +0xc */
};

/* derived names: a node holding a node at +0x28 and a list of nodes, the
 * array at +0x30 and its count at +0x38 (as FUN_0059b280). */
struct NodeArray59b4c0 /* derived name */
{
    Node583950 *at(int index) const
    {
        return nodes[index];
    }

    u8 unknown0[0x28];
    Node583950 *child;  /* +0x28 */
    Node583950 **nodes; /* +0x30 */
    unsigned count;     /* +0x38 */
};

/* derived names: a handler whose address FUN_005269a0 takes (lea at
 * 0x527cd6): FUN_005839e0's copy of the state byte from the owner's first
 * list to its second, with the node's 24-byte value copied after it, then
 * each node of its list and the node at +0x28 dispatched (as FUN_0059b280).
 * Returns 0. Handler unknown. */
int FUN_0059b4c0(FrameOwner583950 *self, NodeArray59b4c0 *node) /* derived name */
{
    Value59b4c0 *from =
        self->cursor.select(node) ? reinterpret_cast<Value59b4c0 *>(self->cursor.value()) : 0;
    Value59b4c0 *to =
        self->cursor190.select(node) ? reinterpret_cast<Value59b4c0 *>(self->cursor190.value()) : 0;
    if (from && to) {
        const u8 *state = self->selectState(node);
        *self->cursor190.selectState(node) = state ? *state : 0;
        *to = *from;
        for (unsigned i = 0; i < node->count; ++i)
            self->dispatch(node->at(i));
        self->dispatch(node->child);
    }
    return 0;
}
