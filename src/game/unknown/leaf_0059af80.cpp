/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a node with a list of nodes, the array at +0x30 and its
 * count at +0x38, that its value indexes (FUN_0059af80). */
struct IndexedNode59af80 /* derived name */
{
    u8 unknown0[0x30];
    Node583950 **nodes; /* +0x30 */
    int count;          /* +0x38 */
};

/* derived names: the value of FUN_0059af80's node: the index at +0x4 */
struct Value59af80 /* derived name */
{
    int unknown0;
    int index; /* +0x4 */
};

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x52567e): with its argument in the owner's list and in the state 1,
 * dispatches the node of its list the index at +0x4 of its value selects,
 * when the index is in the list, through the owner's handler table;
 * returns 0. Handler unknown. */
int FUN_0059af80(FrameOwner583950 *self, IndexedNode59af80 *node) /* derived name */
{
    Value59af80 *value =
        self->cursor.select(node) ? reinterpret_cast<Value59af80 *>(self->cursor.value()) : 0;
    const u8 *state = self->selectState(node);
    const u8 current = state ? *state : 0;
    if (value && current == 1) {
        const int index = value->index;
        if (index >= 0 && index < node->count)
            self->dispatch(node->nodes[index]);
    }
    return 0;
}
