/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

int FUN_00c09230(void *vm, const CallArguments583950 *arguments); /* derived name */

/* derived names: the node FUN_00c0e720 is given: the arguments of the call
 * it appends at +0x28 and the node it hands on at +0x38 */
struct Node00c0e720 { /* derived name */
    u8 unknown0[0x28];
    CallArguments583950 arguments; /* +0x28 */
    Node583950 *held;              /* +0x38 */
};

/* derived names: a handler whose address FUN_00be6da0 takes: the node made
 * the current one and its state byte found (nothing done for a node not in
 * the list); a state of 0 becomes 1 and the held node's state is cleared;
 * in states 0 to 2 the held node is handed to the handler of its kind and,
 * when it had one, a call of FUN_00c09230 with the node's arguments is
 * appended to the frame and the state takes the byte the owner leaves at
 * +0xd8. Returns 0. Handler unknown. */
// NONMATCHING: equal but for the address of FUN_00c09230 (not written): the module takes an
// undefined function's address through the GOT where the base forms it with `lea` (round 484D)
int FUN_00c0e720(FrameOwner583950 *self, Node00c0e720 *node) /* derived name */
{
    u8 *state = self->selectState(node);
    if (!state)
        return 0;
    Node583950 *held = node->held;
    switch (*state) {
    case 0:
        *state = 1;
        if (held)
            self->clearState(held);
    case 1:
    case 2:
        if (held && held->kind) {
            Handler583950 handler = self->handlers[held->kind];
            if (handler) {
                handler(self, held);
                self->frame->push(FUN_00c09230, node->arguments);
                *state = self->unknownd8;
            }
        }
        break;
    }
    return 0;
}
