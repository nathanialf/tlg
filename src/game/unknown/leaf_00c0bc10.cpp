/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

int FUN_00c1da10(Owner583950 *self, void *arg);                   /* derived name */
int FUN_00c09610(void *vm, const CallArguments583950 *arguments); /* derived name */

/* derived names: a handler whose address FUN_00be6da0 takes (lea at
 * 0xbe76d0): runs FUN_00c1da10 on its argument and, when it answers, runs it
 * again from the same current node; when that left the frame two deeper,
 * restores the depth and appends FUN_00c09610 to the frame's calls (one
 * deeper when appended). Sets the float at +0xf4 to -1; returns 0. Handler
 * unknown. */
/* The entry's index is formed before the function's address (`lea rsi, [rsi+rsi*2]` above
 * `lea rdi`): FUN_00c09610 is defined in the module (leaf_00c09610.cpp), so its address is a
 * protected definition's `lea`; a declaration's GOT load is scheduled first. */
int FUN_00c0bc10(FrameOwner583950 *self, void *arg) /* derived name */
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
    self->unknownf4 = -1.0f;
    return 0;
}
