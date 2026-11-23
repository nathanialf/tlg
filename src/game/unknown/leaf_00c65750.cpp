/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: the handler of node kind 17 (FlowAbs) in the tables FUN_00c10ac0, FUN_00be6da0 and FUN_0058d410
 * build: a node not yet in the owner's list of nodes is appended to it and
 * made the current node of the owner's list; then each child of the node
 * dispatches the node it holds at +0x38. Returns 0 (FUN_00594ef0's body).
 * Handler unknown. */
int FUN_00c65750(NodesOwner583950 *self, ParentNode583950Kind17 *node) /* derived name */
{
    if (!self->nodes.contains(node)) {
        self->nodes.push(node);
        self->select(node);
    }
    Node583950 **end = node->children + node->count;
    for (Node583950 **child = node->children; child != end; ++child)
        self->dispatch((*child)->child38);
    return 0;
}
