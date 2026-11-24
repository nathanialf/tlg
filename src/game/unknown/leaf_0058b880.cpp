/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_005269a0 takes (lea at
 * 0x527c03): FUN_005839e0's copy of the state byte from the owner's first
 * list to its second, with the node's int value copied after it, then the
 * nodes at +0x28 and +0x30 dispatched. Returns 0. Handler unknown. */
// NONMATCHING: register assignment (greedy) only: the second list's last search counts in edi
// in the base (`mov edi, edi; cmp [rsi+rdi*8], rbx`), in edx in the build (562 bytes as the
// base, 167 of 172 instructions equal)
// Round 552C, module dump: the third search's counter is a zero-extending MOV32rr from the second
// list's index (rdi, dead there), not a COPY, so it has no hint and takes the first free register,
// rdx; the base's rdi needs rdx held at its assignment (FUN_00584ba0, matched, has its list in
// rdx). An eviction, not visible in the bytes.
int FUN_0058b880(FrameOwner583950 *self, Node583950 *node) /* derived name */
{
    int *from = self->cursor.select(node) ? reinterpret_cast<int *>(self->cursor.value()) : 0;
    int *to = self->cursor190.select(node) ? reinterpret_cast<int *>(self->cursor190.value()) : 0;
    if (from && to) {
        const u8 *state = self->selectState(node);
        *self->cursor190.selectState(node) = state ? *state : 0;
        *to = *from;
        self->dispatch(node->child);
        self->dispatch(node->child30);
    }
    return 0;
}
