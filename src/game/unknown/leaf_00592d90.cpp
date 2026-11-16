/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: the handler of node kind 38 in the table at +0x17a0 of
 * FUN_00525530's object: a node not yet in the owner's list of nodes is
 * appended to it and the device asked for its record, which takes 0 and the
 * node's ints at +0x30, +0x34 and +0x40 to +0x4c; then each child of the
 * node dispatches the node it holds at +0x38. Returns 0. Handler unknown. */
int FUN_00592d90(NodesOwner583950 *self, ParentNode583950Kind38 *node) /* derived name */
{
    if (!self->nodes.contains(node)) {
        self->nodes.push(node);
        Record583950Kind38 *record = static_cast<Record583950Kind38 *>(
            self->device->vtable->method0(self->device, node, sizeof(Record583950Kind38)));
        if (record) {
            record->unknown0 = 0;
            record->unknown4 = node->unknown30;
            record->unknown8 = node->unknown34;
            for (int i = 0; i < 4; ++i)
                record->unknown10[i] = node->unknown40[i];
        }
    }
    Node583950 **end = node->children + node->count;
    for (Node583950 **child = node->children; child != end; ++child)
        self->dispatch((*child)->child38);
    return 0;
}
