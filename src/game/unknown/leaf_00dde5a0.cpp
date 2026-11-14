/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: marks a node and, depth first, every node under it: sets
 * bit 0 of the node's word at +0x0, then of each child's in the pointer
 * array at +0x40 (its count at +0x38) before descending into it. Called
 * from FUN_00dc31a0 with the same first argument, passed on unchanged. The
 * first argument and the nodes are not traced. */
struct Object00dde5a0; /* derived name */

struct Node00dde5a0 { /* derived name */
    u64 flags0;       /* +0x0: bit 0 the mark */
    u8 unknown8[0x30];
    u32 unknown38; /* +0x38: the count of +0x40 */
    u8 unknown3c[4];
    Node00dde5a0 **unknown40; /* +0x40: the children */
};

void FUN_00dde5a0(Object00dde5a0 *self, Node00dde5a0 *node) /* derived name */
{
    node->flags0 |= 1;
    for (u32 i = 0; i < node->unknown38; i++) {
        node->unknown40[i]->flags0 |= 1;
        FUN_00dde5a0(self, node->unknown40[i]);
    }
}
