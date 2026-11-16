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

/* derived names: a handler whose address FUN_00525530 and FUN_005f2b90 take (lea at
 * 0x525cf6 and 0x5f2db7): dispatches the node at +0x28 of its argument, then each node of its list, through
 * the owner's handler table; returns 0. Handler unknown. */
int FUN_00584a30(Owner583950 *self, void *arg) /* derived name */
{
    NodeArray584a30 *list = static_cast<NodeArray584a30 *>(arg);
    self->dispatch(list->child);
    Node583950 **end = list->nodes + list->count;
    for (Node583950 **node = list->nodes; node != end; ++node)
        self->dispatch(*node);
    return 0;
}
