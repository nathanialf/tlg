/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a node with flags at +0x28 and a list of nodes, the array
 * at +0x30 and its count at +0x38 (FUN_00584700). */
struct StateNodeArray584700 /* derived name */
{
    u8 unknown0[0x28];
    u8 flags; /* +0x28 */
    u8 unknown29[7];
    Node583950 **nodes; /* +0x30 */
    unsigned count;     /* +0x38 */
};

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x525842): makes its argument the owner's current node
 * (Owner583950::selectState); the state 0 becomes 1 and the state of each
 * node of its list cleared (Owner583950::clearState); then in the state 1, without bit 0 of its
 * flags, dispatches each node of its list through the owner's handler table
 * and copies the state to the owner's +0xd8 (as FUN_00583bb0); returns 0.
 * Handler unknown. */
int FUN_00584700(Owner583950 *self, StateNodeArray584700 *node) /* derived name */
{
    u8 *state = self->selectState(node);
    switch (*state) {
    case 0: {
        *state = 1;
        Node583950 **end = node->nodes + node->count;
        for (Node583950 **child = node->nodes; child != end; ++child)
            self->clearState(*child);
    }
    case 1:
        if (!(node->flags & 1)) {
            Node583950 **end = node->nodes + node->count;
            for (Node583950 **child = node->nodes; child != end; ++child)
                self->dispatch(*child);
            self->unknownd8 = *state;
        }
        break;
    }
    return 0;
}
