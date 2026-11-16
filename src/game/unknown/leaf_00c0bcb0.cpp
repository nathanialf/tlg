/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

int FUN_00c1dbe0(Owner583950 *self, void *arg); /* derived name */
void FUN_00c09610(void *vm);                    /* derived name */

/* derived names: a handler whose address FUN_00be6da0 takes (lea at
 * 0xbe76f6): runs FUN_00c1dbe0 on its argument and, when it answers, runs it
 * again from the same current node; when that left the frame two deeper,
 * restores the depth and appends FUN_00c09610 to the frame's calls (one
 * deeper when appended). Sets the float at +0xf4 to -1; returns 0. Handler
 * unknown. */
// NONMATCHING: list-ilp order, the base computes the entry's index (lea rsi, [rsi + rsi*2]) before the function's address (lea rdi, [rip]); 43/45, else equal
int FUN_00c0bcb0(Owner583950 *self, void *arg) /* derived name */
{
    const unsigned current = self->current;
    const int depth = self->frame->depth;
    if (FUN_00c1dbe0(self, arg)) {
        self->current = current;
        FUN_00c1dbe0(self, arg);
        if (self->frame->depth - 2 == depth) {
            self->frame->depth = depth;
            self->frame->pushDeeper(FUN_00c09610);
        }
    }
    self->vector[1] = -1.0f;
    return 0;
}
