/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a node with flags at +0x28 and two nodes at +0x30 and
 * +0x38 (FUN_00584070, as FUN_00584240's). */
struct StatePair584070 /* derived name */
{
    u8 unknown0[0x28];
    u8 flags; /* +0x28 */
    u8 unknown29[7];
    Node583950 *first;  /* +0x30 */
    Node583950 *second; /* +0x38 */
};

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x525789): makes its argument the owner's current node (Owner583950::selectState); the state
 * 0 becomes 1 and the states of its two nodes are cleared
 * (Owner583950::clearState); then in the state 1 dispatches its first
 * node, then its second without bit 0 of its flags (both read before the
 * state is tested), and copies the state to the owner's +0xd8 (FUN_00584240
 * without the clearing); returns 0. Handler unknown. */
int FUN_00584070(Owner583950 *self, StatePair584070 *node) /* derived name */
{
    u8 *state = self->selectState(node);
    Node583950 *first = node->first;
    Node583950 *second = node->second;
    switch (*state) {
    case 0:
        *state = 1;
        if (first)
            self->clearState(first);
        if (second)
            self->clearState(second);
    case 1:
        self->dispatch(first);
        if (!(node->flags & 1))
            self->dispatch(second);
        self->unknownd8 = *state;
        break;
    }
    return 0;
}
