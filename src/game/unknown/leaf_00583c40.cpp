/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler of the owner's list: its argument made the
 * current node, searched from the current index to the end and then from
 * the start with no end (the node is in the list); a state of 0 or 1 is
 * copied to the owner's +0xd8 unless bit 0 of the node's flags is set, as
 * FUN_00583bb0 does without starting the state. Returns 0. Handler
 * unknown. */
/* derived name: the index of a node the list holds, searched from the
 * current index to the end, then from the start with no end */
static inline unsigned indexOf(const NodeCursor583950 &cursor, void *node)
{
    const NodeList583950 *nodes = cursor.list;
    for (unsigned at = cursor.current; at < nodes->count; ++at) {
        if (nodes->items[at] == node)
            return at;
    }
    unsigned at = ~0u;
    while (nodes->items[++at] != node) {}
    return at;
}

int FUN_00583c40(Owner583950 *self, StateNode583950 *node) /* derived name */
{
    const unsigned i = indexOf(self->cursor, node);
    self->cursor.current = i;
    const u8 state = self->cursor.list->states[i];
    if (state <= 1 && !(node->flags & 1))
        self->unknownd8 = state;
    return 0;
}
