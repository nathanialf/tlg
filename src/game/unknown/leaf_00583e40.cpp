/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_005269a0 takes (lea at
 * 0x527ca9): FUN_005839e0's copy of the state byte from the owner's first
 * list to its second, then the nodes at +0x30 and +0x38 dispatched.
 * Returns 0. Handler unknown. */
// NONMATCHING: register assignment (greedy) only: the state byte the base carries in r8 (`xor
// r8d, r8d; mov r8b, [rax]`) is in eax in the build, and the second list's search counter
// follows (555 bytes of 556; every block and instruction otherwise the base's)
int FUN_00583e40(FrameOwner583950 *self, Node583950 *node) /* derived name */
{
    char *from = self->cursor.select(node) ? self->cursor.value() : 0;
    char *to = self->cursor190.select(node) ? self->cursor190.value() : 0;
    if (from && to) {
        const u8 *state = self->selectState(node);
        *self->cursor190.selectState(node) = state ? *state : 0;
        self->dispatch(node->child30);
        self->dispatch(node->child38);
    }
    return 0;
}
