/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: the 0x18-byte slot FUN_0059b280 asks the device for and
 * clears: an int at +0x0 and two eight-byte fields after it. */
struct Slot59b280 /* derived name */
{
    int unknown0;
    void *unknown8;  /* +0x8 */
    void *unknown10; /* +0x10 */
};

/* derived names: a node holding a node at +0x28 and a list of nodes, the
 * array at +0x30 and its count at +0x38 (as FUN_0059b340). */
struct NodeArray59b280 /* derived name */
{
    Node583950 *at(int index) const
    {
        return nodes[index];
    }

    u8 unknown0[0x28];
    Node583950 *child;  /* +0x28 */
    Node583950 **nodes; /* +0x30 */
    unsigned count;     /* +0x38 */
};

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x525a01): asks the device at +0xf0 for a 0x18-byte slot for its argument
 * (method 0) and clears it when it gets one, then dispatches each node of its
 * argument's list and the node at +0x28 through the owner's handler table
 * (as FUN_0059b340); returns 0. Handler unknown. */
int FUN_0059b280(Owner583950 *self, void *arg) /* derived name */
{
    Slot59b280 *slot = static_cast<Slot59b280 *>(
        self->device->vtable->method0(self->device, arg, sizeof(Slot59b280)));
    if (slot) {
        slot->unknown0 = 0;
        slot->unknown8 = 0;
        slot->unknown10 = 0;
    }
    NodeArray59b280 *list = static_cast<NodeArray59b280 *>(arg);
    for (unsigned i = 0; i < list->count; ++i)
        self->dispatch(list->at(i));
    self->dispatch(list->child);
    return 0;
}
