/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_node.h"

/* derived name: a node a node of FUN_00585ec0's kind refers to: a counted
 * object whose kind the owner's table is indexed by (Node583950's +0x24) */
class Child585ec0 : public Object016b9108 /* derived name */
{
};

/* derived names: a node holding counted references to other nodes, the
 * array at +0x28 and its count (an int) at +0x30 */
struct Node585ec0 { /* derived name */

    /* a reference to the node at an index, empty for an index outside the
     * array */
    Ref00503fb0<Child585ec0> child(int index) const
    {
        if (index >= 0 && index < count)
            return Ref00503fb0<Child585ec0>(children[index]);
        return Ref00503fb0<Child585ec0>();
    }

    u8 unknown0[0x28];
    Child585ec0 **children; /* +0x28 */
    int count;              /* +0x30 */
};

/* derived name: the two indices of the node's children its value selects,
 * -1 each when none */
void FUN_00bde500(Node585ec0 *node, const void *value, int *first, int *second);

/* derived names: a handler whose address FUN_00525530 takes: when the node
 * is in the owner's first list, FUN_00bde500 picks two of its children from
 * its value, and the two are dispatched, the first then the second.
 * Returns 0. Handler unknown. */
// NONMATCHING: 0x3cbaf0's class: the base keeps each child apart from its reference's
// register (r15: 0 on the null and out-of-range edges, `mov r15, r12` on every edge through the
// reference's raise and drop) and compares the index first (`cmp eax, [rbx+0x30]`); the
// build merges the child with the reference's register
int FUN_00585ec0(Owner583950 *self, Node585ec0 *node) /* derived name */
{
    const void *value = self->cursor.select(node) ? self->cursor.value() : 0;
    if (!value)
        return 0;
    int first = -1;
    int second = -1;
    FUN_00bde500(node, value, &first, &second);
    Child585ec0 *a = node->child(first).get();
    Child585ec0 *b = node->child(second).get();
    self->dispatch(reinterpret_cast<Node583950 *>(a));
    self->dispatch(reinterpret_cast<Node583950 *>(b));
    return 0;
}
