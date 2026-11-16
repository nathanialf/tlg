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

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x525a1d): gives its argument to the device at
 * +0xf0 (method 0 with 1, its answer unused), then dispatches each node of its argument's list through the
 * owner's handler table; returns 0. Handler unknown. */
int FUN_00584330(DeviceOwner583950 *self, void *arg) /* derived name */
{
    self->device->vtable->method0(self->device, arg, 1);
    NodeArray5843b0 *list = static_cast<NodeArray5843b0 *>(arg);
    Node583950 **end = list->nodes + list->count;
    for (Node583950 **node = list->nodes; node != end; ++node)
        self->dispatch(*node);
    return 0;
}
