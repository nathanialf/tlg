/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: the handler of node kind 44 in the table at +0x17a0 of
 * FUN_00525530's object: a node not yet in the owner's list of nodes is
 * appended to it and the device asked for its record, four floats that
 * become (0, 0, 0, 1); then each child of the node dispatches the node it
 * holds at +0x38. Returns 0. Handler unknown. */
int FUN_00590130(NodesOwner583950 *self, ParentNode583950Kind44 *node) /* derived name */
{
    if (!self->nodes.contains(node)) {
        self->nodes.push(node);
        Float4 *record = static_cast<Float4 *>(
            self->device->vtable->method0(self->device, node, sizeof(Float4)));
        if (record)
            *record = Float4(0.0f, 0.0f, 0.0f, 1.0f);
    }
    Node583950 **end = node->children + node->count;
    for (Node583950 **child = node->children; child != end; ++child)
        self->dispatch((*child)->child38);
    return 0;
}
