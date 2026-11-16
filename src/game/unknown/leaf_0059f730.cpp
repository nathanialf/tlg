/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x527c34), the body of FUN_005839e0 (leaf_005839e0.cpp, where it is described).
 * Handler unknown. */
int FUN_0059f730(ValueOwner583950 *self, Node583950 *node) /* derived name */
{
    char *from = self->cursor.select(node) ? self->cursor.value() : 0;
    char *to = self->cursor190.select(node) ? self->cursor190.value() : 0;
    if (from && to) {
        const u8 *state = self->selectState(node);
        *self->cursor190.selectState(node) = state ? *state : 0;
    }
    return 0;
}
