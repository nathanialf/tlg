/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_libc.h"

/* derived names: the node FUN_00c06280 is given: its children at +0x28 */
struct Node00c06280 { /* derived name */
    u8 unknown0[0x28];
    Node583950 **children; /* +0x28 */
    unsigned count;        /* +0x30 */
};

/* derived names: the part of the node's value from +0x38: two blocks the
 * handler clears, the one at +0x318 first (the part's address is formed
 * before either, `lea r15, [rdi+0x38]` ahead of the first memset) */
struct Body00c06280 { /* derived name */

    void clear()
    {
        memset(block318, 0, sizeof(block318));
        memset(block0, 0, sizeof(block0));
    }

    u8 block0[0x310];
    u8 unknown310[0x8];
    u8 block318[0xe80]; /* +0x318 */
};

/* derived names: the node's value in the owner's list */
struct Record00c06280 { /* derived name */
    u8 unknown0[0x38];
    Body00c06280 body; /* +0x38 */
};

/* derived names: a handler whose address FUN_00525530, FUN_00be6da0,
 * FUN_00aec5d0, FUN_00c10ac0 and FUN_0058d410 take: the node is made the
 * current one of the owner's list and its value's two blocks cleared, when
 * it is in the list and has one; then each child of the node is handed to
 * the handler of its kind. Returns 0. Handler unknown. */
int FUN_00c06280(Owner583950 *self, void *arg) /* derived name */
{
    Node00c06280 *node = static_cast<Node00c06280 *>(arg);
    unsigned found;
    if (self->find(node, found)) {
        self->cursor.current = found;
        Record00c06280 *record = reinterpret_cast<Record00c06280 *>(self->currentValue());
        if (record)
            record->body.clear();
    }
    Node583950 **end = node->children + node->count;
    for (Node583950 **child = node->children; child != end; ++child)
        self->dispatch(*child);
    return 0;
}
