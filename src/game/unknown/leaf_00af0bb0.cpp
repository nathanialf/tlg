/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_00aec5d0 takes (lea at
 * 0xaec7a0), the body of FUN_00af09d0 (leaf_00af09d0.cpp, where it is
 * described). Handler unknown. */
int FUN_00af0bb0(ValueOwner583950 *self, Node583950 *node) /* derived name */
{
    unsigned index;
    if (self->cursor.find(node, index)) {
        self->cursor.current = index;
        unsigned index190;
        if (self->cursor190.find(node, index190)) {
            self->cursor190.current = index190;
            self->cursor190.list->states[index190] = self->cursor.list->states[index];
        }
    }
    self->dispatch(node->child);
    return 0;
}
