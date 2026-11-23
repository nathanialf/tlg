/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: the handler of node kind 18 (FlowEase) in the tables
 * FUN_00be6da0, FUN_00c03090 and FUN_00c024a0 build: a node not yet in the
 * owner's list of nodes is appended to it and handed to the device with
 * 20; then each child of the node dispatches the node it holds at +0x38.
 * Returns 0 (FUN_00594d90's body). Handler unknown. */
int FUN_00c65490(NodesOwner583950 *self, ParentNode583950Kind18 *node) /* derived name */
{
    if (!self->nodes.contains(node)) {
        self->nodes.push(node);
        self->device->vtable->method0(self->device, node, 20);
    }
    Node583950 **end = node->children + node->count;
    for (Node583950 **child = node->children; child != end; ++child)
        self->dispatch((*child)->child38);
    return 0;
}
