/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: the handler of node kind 40 in the table at +0x17a0 of
 * FUN_00525530's object: a node not yet in the owner's list of nodes is
 * appended to it and the device asked for its record, whose floats at +0x0
 * to +0x20 and +0x30 and int at +0x20 are cleared; then each child of the
 * node dispatches the node it holds at +0x38. Returns 0. Handler unknown. */
// NONMATCHING: instruction order of the merged zero stores: the base stores +0x30 (xmm) before
// +0x0 (ymm) and +0x20; the build stores +0x0, +0x20, then +0x30, in either source order
// (the stores are merged in the DAG, not by the source's order)
int FUN_00593b30(NodesOwner583950 *self, ParentNode583950Kind40 *node) /* derived name */
{
    if (!self->nodes.contains(node)) {
        self->nodes.push(node);
        Record583950Kind40 *record = static_cast<Record583950Kind40 *>(
            self->device->vtable->method0(self->device, node, sizeof(Record583950Kind40)));
        if (record) {
            record->unknown0 = Float4(0.0f, 0.0f, 0.0f, 0.0f);
            record->unknown10 = Float4(0.0f, 0.0f, 0.0f, 0.0f);
            record->unknown20 = 0;
            record->unknown30 = Float4(0.0f, 0.0f, 0.0f, 0.0f);
        }
    }
    Node583950 **end = node->children + node->count;
    for (Node583950 **child = node->children; child != end; ++child)
        self->dispatch((*child)->child38);
    return 0;
}
