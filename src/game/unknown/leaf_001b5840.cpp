/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: a tree of nodes, each with an array of its children at
 * +0x40 and an id at +0x210, searched by FUN_001b11d0. Nothing else of the
 * node or the key is traced. */
struct Node001b5840 { /* derived name */
    u8 unknown0[0x40];
    Array05943280<Node001b5840 *> children; /* +0x40 */
    u8 unknown58[0x1b8];
    int id; /* +0x210 */
};

struct Key001b5840 { /* derived name */
    int id;          /* +0x0 */
};

/* the node whose id is the key's, the node itself first, then each child's
 * subtree in turn (the count read once); null when there is none */
Node001b5840 *FUN_001b5840(const Key001b5840 *key, Node001b5840 *node) /* derived name */
{
    if (!node)
        return 0;
    if (node->id == key->id)
        return node;
    const unsigned count = node->children.size();
    for (unsigned i = 0; i < count; ++i) {
        Node001b5840 *found = FUN_001b5840(key, node->children.at(i));
        if (found)
            return found;
    }
    return 0;
}
