/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 5 of the world's object at +0x388: skips the run of
 * nodes sharing the first one's key and returns the node after it (null at
 * the end of the list). */
hknpWorldObject388Node *hknpWorldObject388::FUN_0006c2d0(hknpWorldObject388Node *first)
{
    u8 key = first->key;
    hknpWorldObject388Node *node = first;
    do {
        node = static_cast<hknpWorldObject388Node *>(node->next);
    } while (node && node->key == key);
    return node;
}
