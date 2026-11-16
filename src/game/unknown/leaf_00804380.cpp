/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_types.h"

/* derived names: a node of a tree: its children an array at +0x40 and its
 * key at +0x210 */
struct Node00804380 { /* derived name */
    u8 unknown0[0x40];
    Array05943280<Node00804380 *> children; /* +0x40 */
    u8 unknown58[0x1b8];
    int key; /* +0x210 */
};

/* derived names: the node, or the first under it depth first, whose key is
 * the one asked for, else null (the count read once) */
Node00804380 *FUN_00804380(Node00804380 *node, const int &key) /* derived name */
{
    if (node->key == key)
        return node;
    const unsigned count = node->children.size();
    for (unsigned i = 0; i < count; ++i)
        if (Node00804380 *found = FUN_00804380(node->children.at(i), key))
            return found;
    return 0;
}

/* derived names: the child of a node FUN_00c57870 finds by a key, from the
 * index `next` points to (none: from the first); not traced further */
void *FUN_00c57870(Node00804380 *node, u64 key, unsigned *next); /* derived name */

extern u64 D_59453d0; /* derived name: the key */

/* derived names: the node, or the first child depth first whose subtree
 * holds one, for which FUN_00c57870 finds the key D_59453d0, else null; the
 * child is read again for the result */
Node00804380 *FUN_00804d70(Node00804380 *node) /* derived name */
{
    if (!node)
        return 0;
    if (FUN_00c57870(node, D_59453d0, 0))
        return node;
    for (unsigned i = 0; i < node->children.size(); ++i)
        if (FUN_00804d70(node->children.at(i)))
            return node->children.at(i);
    return 0;
}
