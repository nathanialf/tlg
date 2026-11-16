/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: the handler of node kind 42 in the table at +0x1ba0 of
 * FUN_00525530's object: a node not yet in the owner's list of nodes is
 * appended to it and made the current node of the owner's list; then each
 * child of the node dispatches the node it holds at +0x38. Returns 0.
 * Handler unknown. */
int FUN_00590910(NodesOwner583950 *self, ParentNode583950Kind42 *node) /* derived name */
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
