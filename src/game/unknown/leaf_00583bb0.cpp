/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x5257cf): makes its argument the owner's current node
 * (Owner583950::selectState) and starts the node's state byte: 0 becomes 1,
 * and a state of 1 is copied to the owner's +0xd8 unless bit 0 of the
 * node's flags is set; returns 0. Handler unknown. */
// NONMATCHING: 30/45 without the scheduler flag (equal only under the removed -pre-RA-sched=list-ilp; round 250D measured it there): re-work with the reads in the base's order
int FUN_00583bb0(Owner583950 *self, StateNode583950 *node) /* derived name */
{
    u8 *state = self->selectState(node);
    switch (*state) {
    case 0:
        *state = 1;
    case 1:
        if (!(node->flags & 1))
            self->unknownd8 = *state;
        break;
    }
    return 0;
}
