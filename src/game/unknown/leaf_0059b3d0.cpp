/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a node holding a node at +0x28 and a list of nodes, the array at +0x30
 * and its count at +0x38 (FUN_00584a30, FUN_0059b340). */
struct NodeArray584a30 /* derived name */
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
 * 0x525be9): makes its argument the owner's current node
 * (Owner583950::select), then FUN_0059b340's body: dispatches each node of
 * its list, then the node at +0x28, through the owner's handler table;
 * returns 0. Handler unknown. */
int FUN_0059b3d0(Owner583950 *self, NodeArray584a30 *list) /* derived name */
{
    self->select(list);
    for (unsigned i = 0; i < list->count; ++i)
        self->dispatch(list->at(i));
    self->dispatch(list->child);
    return 0;
}
