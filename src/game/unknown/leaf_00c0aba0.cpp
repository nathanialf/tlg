/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

int FUN_00e03530(void *vm, const CallArguments583950 *arguments); /* derived name */

/* derived names: a handler whose address FUN_00be6da0 takes: with its node
 * in the owner's list (its value found), in the state 0 the state becomes 1
 * and the state bytes of the node's children at +0x28 (twice, as the base
 * does) and +0x38 are cleared; in the state 1 those children are handed on
 * by kind (the one at +0x28 twice, then the one at +0x38), and when that
 * left the frame three deeper the depth is restored and FUN_00e03530
 * appended to the frame's calls (one deeper when appended). The state is
 * left at +0xd8. Returns 0. Handler unknown. */
// NONMATCHING: waits for FUN_00e03530 (0xf8 bytes) defined in the module, as FUN_00c0bc10 waits
// for FUN_00c09610: the base forms the function's address with `lea rdi, [rip]` after the
// entry's index; a declaration's GOT load is scheduled first. Before it, the value: the base keeps
// the pointer (0 where not found) and tests it after the state's search (`test r8, r8`), the build
// folds the test into each arm (`setne r8b`), which moves the first search's arms
int FUN_00c0aba0(FrameOwner583950 *self, Node583950 *node) /* derived name */
{
    void *value = self->cursor.select(node) ? self->cursor.value() : 0;
    u8 *state = self->selectState(node);
    if (!value)
        return 0;
    Node583950 *first = node->child;
    Node583950 *second = node->child38;
    switch (*state) {
    case 0:
        *state = 1;
        if (first) {
            self->clearState(first);
            self->clearState(first);
        }
        if (second)
            self->clearState(second);
    case 1: {
        const int depth = self->frame->depth;
        self->dispatch(first);
        self->dispatch(first);
        self->dispatch(second);
        if (self->frame->depth - 3 == depth) {
            self->frame->depth = depth;
            self->frame->pushDeeper(FUN_00e03530);
        }
        break;
    }
    }
    self->unknownd8 = *state;
    return 0;
}
