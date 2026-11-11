/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears bit 3 of the byte at +0x16 of the record the pointer
 * at +0x18 refers to (when set), then does the same for each child (the
 * pointers at +0x38, counted by the unsigned int at +0x40), recursively.
 * Called by FUN_00c70f50. The record's other fields are not traced. */
struct Record00c7aa70 { /* derived name */
    u8 unknown0[0x16];
    u8 flags16; /* +0x16 */
};

struct Node00c7aa70;

struct NodeArray00c7aa70 { /* derived name */
    Node00c7aa70 **data;   /* derived name */
    u32 count;             /* derived name */

    Node00c7aa70 **begin() const
    {
        return data;
    }

    Node00c7aa70 **end() const
    {
        return data + count;
    }
};

struct Node00c7aa70 { /* derived name */
    u8 unknown0[0x18];
    Record00c7aa70 *unknown18; /* +0x18 */
    u8 unknown20[0x18];
    NodeArray00c7aa70 children; /* +0x38, derived name */
};

void FUN_00c7aa70(Node00c7aa70 *node) /* derived name */
{
    if (node->unknown18)
        node->unknown18->flags16 &= ~8;
    for (Node00c7aa70 *child : node->children)
        FUN_00c7aa70(child);
}
