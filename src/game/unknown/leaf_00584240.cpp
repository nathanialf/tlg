/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a node with flags at +0x28 and two nodes at +0x30 and
 * +0x38 (FUN_00584240). */
struct StatePair584240 /* derived name */
{
    u8 unknown0[0x28];
    u8 flags; /* +0x28 */
    u8 unknown29[7];
    Node583950 *first;  /* +0x30 */
    Node583950 *second; /* +0x38 */
};

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x525f1d): makes its argument the owner's current node
 * (Owner583950::selectState); in the state 0 or 1, dispatches its first
 * node, then its second without bit 0 of its flags (both read before the
 * first is handled: `mov rsi, [rbx+0x30]; mov r15, [rbx+0x38]` before the
 * call), and copies the state to the owner's +0xd8; returns 0. Handler
 * unknown. */
int FUN_00584240(Owner583950 *self, StatePair584240 *node) /* derived name */
{
    u8 *state = self->selectState(node);
    switch (*state) {
    case 0:
    case 1: {
        Node583950 *first = node->first;
        Node583950 *second = node->second;
        self->dispatch(first);
        if (!(node->flags & 1))
            self->dispatch(second);
        self->unknownd8 = *state;
        break;
    }
    }
    return 0;
}
