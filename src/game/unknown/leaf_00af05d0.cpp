/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_00aec5d0 takes (lea at
 * 0xaec742), of FUN_00af09d0's family: the node made the current one of the
 * owner's list and, when it is there, of the second list at +0x190 too,
 * whose state byte then takes the first's and whose value the first's int;
 * then, the node made current again, the child its value names (the node's
 * children at +0x28) is made current and dispatched when its state byte
 * is 1. Returns 0. Handler unknown. */
struct ParentNode00af05d0 { /* derived name */
    u8 unknown0[0x28];
    Node583950 **children; /* +0x28 */
};

int FUN_00af05d0(FrameOwner583950 *self, ParentNode00af05d0 *node) /* derived name */
{
    unsigned index;
    if (self->cursor.find(node, index)) {
        self->cursor.current = index;
        const int *from = reinterpret_cast<const int *>(self->cursor.value());
        unsigned index190;
        if (self->cursor190.find(node, index190)) {
            self->cursor190.current = index190;
            self->cursor190.list->states[index190] = self->cursor.list->states[index];
            int *to = reinterpret_cast<int *>(self->cursor190.value());
            to[0] = from[0];
            if (self->cursor.select(node)) {
                if (const int *value = reinterpret_cast<const int *>(self->cursor.value())) {
                    Node583950 *child = node->children[*value];
                    u8 *state = self->cursor.selectState(child);
                    if (state && *state == 1)
                        self->dispatch(child);
                }
            }
        }
    }
    return 0;
}
