/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x527cb9; 0x599a10 and 0x59f730 are the same body): the node made the
 * current one of both of the owner's lists; when it has a value in each, the
 * second list's state byte takes the first's. Returns 0. Handler unknown. */
int FUN_005839e0(FrameOwner583950 *self, Node583950 *node) /* derived name */
{
    char *from = self->cursor.select(node) ? self->cursor.value() : 0;
    char *to = self->cursor190.select(node) ? self->cursor190.value() : 0;
    if (from && to) {
        const u8 *state = self->selectState(node);
        *self->cursor190.selectState(node) = state ? *state : 0;
    }
    return 0;
}
