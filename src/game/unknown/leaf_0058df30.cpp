/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_node.h"
#include "tlg_math.h"

/* derived names: the value FUN_0058df30 copies between the owner's two
 * lists: a counted reference another thread may replace, 0x28 bytes not
 * traced and a vector. 0x40 bytes. */
struct Value58df30 /* derived name */
{
    /* the copy member by member: the 0x28 bytes after the reference and the
     * vector are copied apart (`mov rax, [r12+0x28]` and a 32-byte move,
     * then an aligned 16-byte move at +0x30); the implicit assignment copies
     * the 0x38 bytes after the reference as one block */
    Value58df30 &operator=(const Value58df30 &other)
    {
        reference = other.reference;
        memcpy(unknown8, other.unknown8, sizeof(unknown8));
        vector = other.vector;
        return *this;
    }

    AtomicRef0045c470<Object016b9108> reference;
    u8 unknown8[0x28];
    Float4A vector; /* +0x30 */
};

/* derived name: a node holding a node at +0x28 */
struct Node58df30 /* derived name */
{
    u8 unknown0[0x28];
    Node583950 *child; /* +0x28 */
};

/* derived names: a handler whose address FUN_005269a0 takes: FUN_005839e0's
 * copy of the state byte from the owner's first list to its second, with
 * the node's value copied after it (the reference exchanged), then the node
 * at +0x28 dispatched. Returns 0. Handler unknown. */
int FUN_0058df30(FrameOwner583950 *self, Node58df30 *node) /* derived name */
{
    Value58df30 *from =
        self->cursor.select(node) ? reinterpret_cast<Value58df30 *>(self->cursor.value()) : 0;
    Value58df30 *to =
        self->cursor190.select(node) ? reinterpret_cast<Value58df30 *>(self->cursor190.value()) : 0;
    if (from && to) {
        const u8 *state = self->selectState(node);
        *self->cursor190.selectState(node) = state ? *state : 0;
        *to = *from;
        self->dispatch(node->child);
    }
    return 0;
}
