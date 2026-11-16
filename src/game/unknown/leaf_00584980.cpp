/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a node holding a node at +0x28 and a list of nodes, the
 * array at +0x30 and its count at +0x38 (FUN_00584980). */
struct NodeArray584980 /* derived name */
{
    u8 unknown0[0x28];
    Node583950 *child;  /* +0x28 */
    Node583950 **nodes; /* +0x30 */
    unsigned count;     /* +0x38 */
};

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x525941): asks the device at +0xf0 for a 4-byte slot for its argument
 * (method 0 with 4, as FUN_00c02790) and stores 1.0f there when it gets one,
 * then dispatches the node at +0x28 of its argument and each node of its list
 * through the owner's handler table; returns 0. Handler unknown. */
int FUN_00584980(Owner583950 *self, void *arg) /* derived name */
{
    float *value = static_cast<float *>(self->device->vtable->method0(self->device, arg, 4));
    if (value)
        *value = 1.0f;
    NodeArray584980 *list = static_cast<NodeArray584980 *>(arg);
    self->dispatch(list->child);
    Node583950 **end = list->nodes + list->count;
    for (Node583950 **node = list->nodes; node != end; ++node)
        self->dispatch(*node);
    return 0;
}
