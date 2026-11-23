/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"

/* derived names: a node of the ordered tree FUN_004f7900 empties: its
 * left, parent and right links, the colour and the end marker after them,
 * then the key and a block the node owns */
struct Node005006b0 {     /* derived name */
    Node005006b0 *left;   /* +0x0 */
    Node005006b0 *parent; /* +0x8 */
    Node005006b0 *right;  /* +0x10 */
    char color;           /* +0x18 */
    char isNil;           /* +0x19 */
    u8 unknown1a[0x6];
    void *key;   /* +0x20: not traced */
    void *block; /* +0x28: released with the node */
};

/* derived name: the subtree under a node erased: each right subtree first,
 * then the node's block released and the node deleted, down the left links
 * to the end marker */
void FUN_005006b0(Node005006b0 *node)
{
    while (!node->isNil) {
        FUN_005006b0(node->right);
        Node005006b0 *erased = node;
        node = node->left;
        releaseBlock(erased->block);
        delete erased;
    }
}
