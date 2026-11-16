/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a node holding a list of nodes, the array at +0x28 and
 * its count at +0x30 (FUN_00588580, FUN_005885e0, FUN_00c02040, FUN_00c02330). */
struct NodeArray588580 /* derived name */
{
    u8 unknown0[0x28];
    Node583950 **nodes; /* +0x28 */
    unsigned count;     /* +0x30 */
};

/* derived names: a handler whose address FUN_0058c760, FUN_00be6da0, FUN_00c04990,
 * FUN_00c0aeb0 and FUN_00c0e890 take: has the device at +0xf0 give
 * its argument an int (method 0 with 4) and sets it to 0, then dispatches each node of its argument's list
 * through the owner's handler table; returns 0. Handler unknown. */
int FUN_00c032f0(Owner583950 *self, void *arg) /* derived name */
{
    int *value = static_cast<int *>(self->device->vtable->method0(self->device, arg, 4));
    if (value) {
        *value = 0;
    }
    NodeArray588580 *list = static_cast<NodeArray588580 *>(arg);
    Node583950 **end = list->nodes + list->count;
    for (Node583950 **node = list->nodes; node != end; ++node)
        self->dispatch(*node);
    return 0;
}
