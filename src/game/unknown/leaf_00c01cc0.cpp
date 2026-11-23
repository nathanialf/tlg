/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a node found in the 'XAIT' owner's list whose value holds
 * nodes it has not walked: the ring's entries from the first to the last
 * are copied, then each one's node at +0x58 is dispatched by an owner like
 * this one over the entry's list. Returns 0. Handler unknown. */
int FUN_00c01cc0(FrameOwnerBase583950 *self, Node583950 *node) /* derived name */
{
    WalkRing583950 *value =
        self->cursor.select(node) ? reinterpret_cast<WalkRing583950 *>(self->cursor.value()) : 0;
    if (!value || value->walked == value->last)
        return 0;
    Node583950 *nodes[16];
    NodeList583950 *lists[16];
    const unsigned first = value->first;
    const unsigned end = value->last + 1;
    const unsigned count = end - first;
    unsigned taken = 0;
    for (unsigned i = first; i < end; ++i)
        nodes[taken++] = value->nodes[i & 15];
    taken = 0;
    for (unsigned i = first; i < end; ++i)
        lists[taken++] = value->lists[i & 15];
    for (unsigned i = 0; i < count; ++i) {
        FrameOwnerBase583950 owner(*self, lists[i], 0);
        owner.dispatch(nodes[i]->child58);
    }
    return 0;
}
