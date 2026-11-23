/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b85e0.h"

/* derived name: the node of the tree under `node` (itself included) whose
 * Name at +0x210 is `name`, the children searched from the last, each one's
 * own name tested before its subtree; null when none (callers hold the
 * world's reader count: FUN_0048fd50, FUN_00454c70) */
/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: the link never
 * inlines it (cost=never): one signature changes no row) */
Object016b85e0 *FUN_0048fe20(const Name &name, Object016b85e0 *node)
{
    if (!node)
        return 0;
    if (node->name210 == name)
        return node;
    for (int i = node->childCount; i > 0; --i) {
        Object016b85e0 *child = node->children[i - 1].get();
        if (child) {
            if (child->name210 == name)
                return child;
            if (Object016b85e0 *found = FUN_0048fe20(name, child))
                return found;
        }
    }
    return 0;
}
