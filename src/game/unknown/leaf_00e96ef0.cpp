/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: frees a red-black tree's subtree, as a map's node eraser does:
 * for each node down the left links until the head (its byte at +0x19 set),
 * erases the right subtree (+0x10) by recursion, then deletes the node and goes
 * to its left child (+0x0). FUN_00e96c10 calls it (0xe96cab). The nodes'
 * values are not traced. */
struct Node00e96ef0 {     /* derived name */
    Node00e96ef0 *left;   /* derived name */
    Node00e96ef0 *parent; /* derived name; not read here */
    Node00e96ef0 *right;  /* derived name */
    u8 color;             /* derived name; not read here */
    bool isNil;           /* derived name */
};

void FUN_00e96ef0(Node00e96ef0 *node) /* derived name */
{
    while (!node->isNil) {
        FUN_00e96ef0(node->right);
        Node00e96ef0 *left = node->left;
        operator delete(node);
        node = left;
    }
}
