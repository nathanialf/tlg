/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0134f620.h"

/* derived names: the object's five lists of counted references at +0x1e8,
 * +0x200, +0x218, +0x230 and +0x248 are given a new size: nothing when the
 * first already has it; else each is cleared to that capacity
 * (FUN_0138c8d0 with the size, `mov esi, r14d`: the array's clear(unsigned)
 * called with a size that is not a constant, five times), its count set and
 * its entries nulled; with a size of 0 the last four are cleared with 0.
 * Then the 0x210-byte object at +0x5b0 is created when there is none (the
 * vtable 0x16b9290). The owner is not traced. */
struct Object00cca460 { /* derived name */
    u8 unknown0[0x1e8];
    Object0134f620 lists[5]; /* +0x1e8 */
};

// NONMATCHING: only the five lists' clear to the new capacity is written
// (the counts, the nulled entries and the object at +0x5b0 are not).
void FUN_00cca460(Object00cca460 *self, unsigned size) /* derived name */
{
    if (self->lists[0].size() == size)
        return;
    for (int i = 0; i < 5; ++i)
        self->lists[i].clear(size);
}
