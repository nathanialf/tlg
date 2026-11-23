/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: the node FUN_00c04590 is given: its children at +0x28 */
struct ParentNode00c04590 { /* derived name */
    u8 unknown0[0x28];
    Node583950 **children; /* +0x28 */
    unsigned count;        /* +0x30 */
};

/* derived name: the 0x11e0-byte value such a node keeps in each list */
struct Value00c04590 { /* derived name */
    u8 unknown0[0x11e0];
};

/* derived names: a handler of the table FUN_005269a0 builds on its stack
 * (and FUN_00aec5d0's): a node found in both of the 'XAIT' owner's lists has
 * its state byte and its value copied from the first list to the second:
 * a value of 0x11e0 bytes, then each child of the node dispatched. Returns 0. Handler unknown. */
int FUN_00c04590(FrameOwner583950 *self, ParentNode00c04590 *node) /* derived name */
{
    Value00c04590 *from =
        self->cursor.select(node) ? reinterpret_cast<Value00c04590 *>(self->cursor.value()) : 0;
    Value00c04590 *to = self->cursor190.select(node)
                            ? reinterpret_cast<Value00c04590 *>(self->cursor190.value())
                            : 0;
    if (from && to) {
        const u8 *state = self->selectState(node);
        *self->cursor190.selectState(node) = state ? *state : 0;
        *to = *from;
        Node583950 **end = node->children + node->count;
        for (Node583950 **child = node->children; child != end; ++child)
            self->dispatch(*child);
    }
    return 0;
}
