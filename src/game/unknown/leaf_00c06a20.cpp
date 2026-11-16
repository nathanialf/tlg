/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a node holding a list of nodes, the array at +0x28 and its
 * count at +0x30 (FUN_00c06a20). */
struct NodeArrayc06a20 /* derived name */
{
    u8 unknown0[0x28];
    Node583950 **nodes; /* +0x28 */
    unsigned count;     /* +0x30 */
};

/* derived names: a handler whose address FUN_0058d410, FUN_00aec5d0, FUN_00be6da0 and FUN_00c10ac0
 * take (lea at 0x58d4c1, 0xaef9f8, 0xbe77ae and 0xc10c3e): makes its argument the owner's current node
 * (Owner583950::select), then dispatches each node of its argument's list
 * through the owner's handler table; returns 0. Handler unknown. */
int FUN_00c06a20(Owner583950 *self, void *arg) /* derived name */
{
    self->select(arg);
    NodeArrayc06a20 *list = static_cast<NodeArrayc06a20 *>(arg);
    Node583950 **end = list->nodes + list->count;
    for (Node583950 **node = list->nodes; node != end; ++node)
        self->dispatch(*node);
    return 0;
}
