/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include <algorithm>

/* derived names: called by FUN_00ee83f0 and by itself: the product of the
 * floats at +0x2d4 and +0x2d8 of a node, raised to the largest such value of
 * the nodes listed under it (the first at +0x10 of the record its pointer at
 * +0x48 holds, each next at +0x10 of the record the node's pointer at +0x18
 * holds). The records' types are not traced. */
struct Node00edede0;

struct Link00edede0 { /* derived name */
    u8 unknown0[0x10];
    Node00edede0 *node; /* derived name */
};

struct Node00edede0 { /* derived name */
    u8 unknown0[0x18];
    Link00edede0 *next; /* derived name; +0x18 */
    u8 unknown20[0x28];
    Link00edede0 *children; /* derived name; +0x48 */
    u8 unknown50[0x284];
    float unknown2d4;
    float unknown2d8;
};

float FUN_00edede0(Node00edede0 *node) /* derived name */
{
    float level = node->unknown2d4 * node->unknown2d8;
    for (Node00edede0 *child = node->children->node; child; child = child->next->node)
        level = std::max(level, FUN_00edede0(child));
    return level;
}
