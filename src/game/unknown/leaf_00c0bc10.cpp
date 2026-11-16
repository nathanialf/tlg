/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

int FUN_00c1da10(Owner583950 *self, void *arg); /* derived name */
void FUN_00c09610(void *vm);                    /* derived name */

/* derived names: a handler whose address FUN_00be6da0 takes (lea at
 * 0xbe76d0): runs FUN_00c1da10 on its argument and, when it answers, runs it
 * again from the same current node; when that left the frame two deeper,
 * restores the depth and appends FUN_00c09610 to the frame's calls (one
 * deeper when appended). Sets the float at +0xf4 to -1; returns 0. Handler
 * unknown. */
// NONMATCHING: waits for FUN_00c09610 (0x365 bytes) defined in the module: the base computes the entry's index (lea rsi, [rsi + rsi*2]) before the function's address, a protected definition's `lea rdi, [rip]`; a declaration's GOT load is scheduled first (a throwaway single-file compile with the declaration protected was equal, 45/45)
int FUN_00c0bc10(Owner583950 *self, void *arg) /* derived name */
{
    const unsigned current = self->cursor.current;
    const int depth = self->frame->depth;
    if (FUN_00c1da10(self, arg)) {
        self->cursor.current = current;
        FUN_00c1da10(self, arg);
        if (self->frame->depth - 2 == depth) {
            self->frame->depth = depth;
            self->frame->pushDeeper(FUN_00c09610);
        }
    }
    self->vector[1] = -1.0f;
    return 0;
}
