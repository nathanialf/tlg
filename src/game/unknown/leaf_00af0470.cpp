/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_00aec5d0 takes (lea at
 * 0xaec72d), of FUN_00af09d0's family: the node made the current one of the
 * owner's list and, when it is there, of the second list at +0x190 too,
 * whose state byte then takes the first's and whose value takes the first's
 * two ints; the child the second int names (the node's children at +0x30)
 * is dispatched. Returns 0. Handler unknown. */
struct ParentNode00af0470 { /* derived name */
    u8 unknown0[0x30];
    Node583950 **children; /* +0x30 */
};

int FUN_00af0470(FrameOwner583950 *self, ParentNode00af0470 *node) /* derived name */
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
            to[1] = from[1];
            self->dispatch(node->children[from[1]]);
        }
    }
    return 0;
}
