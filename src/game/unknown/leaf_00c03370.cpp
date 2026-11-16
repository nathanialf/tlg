/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a node holding a list of nodes, the array at +0x30 and
 * its count at +0x38 (FUN_005843b0). */
struct NodeArray5843b0 /* derived name */
{
    u8 unknown0[0x30];
    Node583950 **nodes; /* +0x30 */
    unsigned count;     /* +0x38 */
};

/* derived names: a handler whose address FUN_0058c760, FUN_00be6da0, FUN_00c04990,
 * FUN_00c0aeb0 and FUN_00c0e890 take: has the device at +0xf0 give
 * its argument eight bytes (method 0 with 8) and sets them to -1, then dispatches each node of its argument's
 * list through the owner's handler table; returns 0. Handler unknown. */
int FUN_00c03370(Owner583950 *self, void *arg) /* derived name */
{
    s64 *value = static_cast<s64 *>(self->device->vtable->method0(self->device, arg, 8));
    if (value) {
        *value = -1;
    }
    NodeArray5843b0 *list = static_cast<NodeArray5843b0 *>(arg);
    Node583950 **end = list->nodes + list->count;
    for (Node583950 **node = list->nodes; node != end; ++node)
        self->dispatch(*node);
    return 0;
}
