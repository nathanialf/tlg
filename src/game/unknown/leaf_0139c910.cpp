/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: sets the int at +0x450 of a node and, when it changed, of
 * every node below it: the node of each of its links (the pointers from
 * +0x3e8, their count at +0xe4, each link's node at +0x10), recursively.
 * Called directly. Class and method unknown. */
struct Node0139c910; /* derived name */

struct Link0139c910 { /* derived name */
    u8 unknown0[0x10];
    Node0139c910 *node; /* +0x10 */
};

struct Node0139c910 { /* derived name */
    u8 unknown0[0xe4];
    int linkCount; /* +0xe4 */
    u8 unknowne8[0x3e8 - 0xe8];
    Link0139c910 *links[13]; /* +0x3e8, up to +0x450 */
    int unknown450;          /* +0x450 */
};

void FUN_0139c910(Node0139c910 *node, int value) /* derived name */
{
    if (node->unknown450 == value)
        return;
    node->unknown450 = value;
    for (int i = 0; i < node->linkCount; i++)
        FUN_0139c910(node->links[i]->node, value);
}
