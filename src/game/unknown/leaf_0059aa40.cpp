/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a node with an array of nodes at +0x28 that its value
 * indexes (FUN_0059aa40). */
struct IndexedNode59aa40 /* derived name */
{
    u8 unknown0[0x28];
    Node583950 **nodes; /* +0x28 */
};

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x52600e): with its argument in the owner's list and in the state 1,
 * dispatches the node of its array its value (an int) indexes through the
 * owner's handler table; returns 0. Handler unknown. */
// NONMATCHING: the state byte: the base reads it before the value is tested and keeps the
// byte (or 0) as one value tested after it (`mov al, [rax]` ... `test r8, r8; je; movzx eax, al;
// cmp eax, 1`); the build threads the zero arms to the return and reads the byte after the value
// test, as FUN_0059af80's base does with the same source (equal there)
int FUN_0059aa40(FrameOwner583950 *self, IndexedNode59aa40 *node) /* derived name */
{
    int *value = self->cursor.select(node) ? reinterpret_cast<int *>(self->cursor.value()) : 0;
    const u8 *state = self->selectState(node);
    const u8 current = state ? *state : 0;
    if (value && current == 1)
        self->dispatch(node->nodes[*value]);
    return 0;
}
