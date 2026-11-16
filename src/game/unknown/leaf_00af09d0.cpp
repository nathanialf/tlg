/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_00aec5d0 takes (lea at
 * 0xaec7ac; 0xaf0ac0, 0xaf0bb0 and 0xaf0ca0 in the same table are the same
 * body): the node made the current one of the owner's list and, when it is
 * there, of the second list at +0x190 too, whose state byte then takes the
 * first's; the node's child is dispatched. Returns 0. Handler unknown. */
int FUN_00af09d0(Owner583950 *self, Node583950 *node) /* derived name */
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
