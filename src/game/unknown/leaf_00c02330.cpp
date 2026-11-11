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

/* derived names: a handler whose address FUN_005f2b90 and FUN_00be6da0 take: dispatches
 * each node of its argument's list through the owner's handler table;
 * returns 0. Handler unknown. */
int FUN_00c02330(Owner583950 *self, void *arg) /* derived name */
{
    NodeArray588580 *list = static_cast<NodeArray588580 *>(arg);
    Node583950 **end = list->nodes + list->count;
    for (Node583950 **node = list->nodes; node != end; ++node)
        self->dispatch(*node);
    return 0;
}
