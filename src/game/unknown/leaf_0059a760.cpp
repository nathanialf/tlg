/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_array.h"

/* derived names: the node FUN_0059a760 is given: whether it goes on past a
 * child that ends in 2 (+0x28) or in 3 (+0x2c), and its children at +0x30. */
struct ChildrenNode59a760 /* derived name */
{
    u8 unknown0[0x28];
    int continueOn2;                      /* +0x28 */
    int continueOn3;                      /* +0x2c */
    Array05943280<Node583950 *> children; /* +0x30 */
};

/* derived names: a handler whose address FUN_00525530 takes: its node's state
 * byte, 0 on the first call (an empty node ends in 2 at once, else the state
 * bytes of its children are cleared and the node runs as in state 1); in
 * states 1 and 2 each child whose own state is 0 or 1 is handed to the
 * handler of its kind and the owner's +0xd8 it leaves is read: 0 (or a child
 * not handed on) ends the node in 0, 1 leaves it in 1, 2 and 3 end it in 2
 * or 3 unless the node goes on past them; when every child ends in 3 the
 * node ends in 3, else when every child ends in 2 in 2. The state is kept
 * in the byte and at the owner's +0xd8. Returns 0. Handler unknown. */
/* the children of a node in state 1 or 2 handed on in turn: the state the
 * node goes to (derived name) */
static inline int runChildren(Owner583950 *self, ChildrenNode59a760 *node, Handler583950 *table,
                              int running)
{
    unsigned ended2 = 0;
    unsigned ended3 = 0;
    Node583950 *const *end = node->children.end();
    for (Node583950 *const *it = node->children.begin(); it != end; ++it) {
        Node583950 *child = *it;
        const u8 childState =
            self->cursor.select(child) ? self->cursor.list->states[self->cursor.current] : 0;
        int childResult = 0;
        if (child && childState <= 1 && child->kind) {
            Handler583950 handler = table[child->kind];
            if (handler) {
                handler(self, child);
                childResult = self->unknownd8;
            }
        }
        switch (childResult) {
        case 0:
            return 0;
        case 1:
            running = 1;
            break;
        case 2:
            if (!node->continueOn2)
                return 2;
            ++ended2;
            break;
        case 3:
            if (!node->continueOn3)
                return 3;
            ++ended3;
            break;
        }
    }
    const unsigned count = node->children.size();
    return ended3 == count ? 3 : ended2 == count ? 2 : running;
}

// NONMATCHING: each child's state: the base tests the child for null on both arms of the search
// and reads the state byte after that test on the found arm only (the not-found arm goes to the
// kind's test); the build merges the arms into one value (0 where not found) tested after the
// null test; then the running state in r13 where the build spills it
int FUN_0059a760(Owner583950 *self, ChildrenNode59a760 *node) /* derived name */
{
    Handler583950 *table = self->handlers;
    if (!self->cursor.select(node))
        return 0;
    u8 *state = self->currentState();
    int result = *state;
    switch (result) {
    case 0:
        if (node->children.size() == 0) {
            result = 2;
            break;
        }
        {
            Node583950 *const *end = node->children.end();
            for (Node583950 *const *it = node->children.begin(); it != end; ++it)
                self->clearState(*it);
        }
        result = 1;
    case 1:
    case 2:
        result = runChildren(self, node, table, result);
        break;
    }
    *state = result;
    self->unknownd8 = result;
    return 0;
}
