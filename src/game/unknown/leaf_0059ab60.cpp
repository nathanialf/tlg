/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

int FUN_0059ac10(Owner583950 *self, void *arg); /* derived name */
void FUN_0059ae50(void *vm);                    /* derived name */

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x5256ff): runs FUN_0059ac10 on its argument from the same current node for
 * as long as it answers; each pass that left the frame one deeper restores
 * the depth and appends FUN_0059ae50 to the frame's calls. Sets the float at
 * +0xf4 to -1; returns 0. Handler unknown. */
int FUN_0059ab60(Owner583950 *self, void *arg) /* derived name */
{
    const unsigned current = self->cursor.current;
    const int depth = self->frame->depth;
    while (FUN_0059ac10(self, arg)) {
        if (self->frame->depth - 1 == depth) {
            self->frame->depth = depth;
            self->frame->push(FUN_0059ae50);
        }
        self->cursor.current = current;
    }
    self->vector[1] = -1.0f;
    return 0;
}
