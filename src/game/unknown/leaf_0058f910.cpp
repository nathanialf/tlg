/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: the handler of node kind 32 in the table at +0x17a0 of
 * FUN_00525530's object: a node not yet in the owner's list of nodes is
 * appended to it and the device asked for its record, whose ints at +0x4
 * and +0xc are cleared and whose four floats at +0x20 become (0, 0, 0, 1);
 * then each child of the node dispatches the node it holds at +0x38.
 * Returns 0. Handler unknown. */
int FUN_0058f910(NodesOwner583950 *self, ParentNode583950Kind32 *node) /* derived name */
{
    if (!self->nodes.contains(node)) {
        self->nodes.push(node);
        Record583950Kind32 *record = static_cast<Record583950Kind32 *>(
            self->device->vtable->method0(self->device, node, sizeof(Record583950Kind32)));
        if (record) {
            record->floatValue = 0.0f;
            record->intValue = 0;
            record->vector.set(0.0f, 0.0f, 0.0f, 1.0f);
        }
    }
    Node583950 **end = node->children + node->count;
    for (Node583950 **child = node->children; child != end; ++child)
        self->dispatch((*child)->child38);
    return 0;
}
