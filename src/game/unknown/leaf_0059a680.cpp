/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a node with a list of nodes, the array at +0x30 and its
 * count at +0x38 (FUN_0059a680). */
struct NodeArray59a680 /* derived name */
{
    u8 unknown0[0x30];
    Node583950 **nodes; /* +0x30 */
    unsigned count;     /* +0x38 */
};

/* derived names: a handler whose address FUN_00525530 takes: with its
 * argument in the owner's list and in the state 1 (lea at 0x526029), dispatches each node of
 * its list through the owner's handler table; returns 0. Handler unknown. */
// NONMATCHING: the state byte (0x59aa40's class): the base keeps the byte (or 0) as one value
// and tests the list's count before it (`mov r15d, [rsi+0x38]; test r15, r15; je` at the join,
// then `movzx eax, al; cmp eax, 1`); the build threads the zero arms to the return (202 bytes
// of 218), with the count tested first or after alike
int FUN_0059a680(Owner583950 *self, NodeArray59a680 *node) /* derived name */
{
    const u8 *state = self->selectState(node);
    const u8 current = state ? *state : 0;
    if (current == 1) {
        Node583950 **end = node->nodes + node->count;
        for (Node583950 **child = node->nodes; child != end; ++child)
            self->dispatch(*child);
    }
    return 0;
}
