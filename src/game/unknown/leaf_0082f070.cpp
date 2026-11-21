/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_object01388080.h"
#include "tlg_types.h"

/* derived names: the object at +0x118 of the node below: flags at +0x24 */
struct Owner0082f070 { /* derived name */
    u8 unknown0[0x24];
    unsigned flags; /* +0x24 */
};

/* derived names: a node of a tree: its children an array at +0x38, a
 * kind at +0x24 and a state at +0x28 */
struct Node0082f070 { /* derived name */
    u8 unknown0[0x24];
    int kind;  /* +0x24 */
    int state; /* +0x28 */
    u8 unknown2c[0xc];
    Array05943280<Node0082f070 *> children; /* +0x38 */
    u8 unknown50[0xc8];
    Owner0082f070 *owner; /* +0x118 */
};

/* derived names: the node and every node under it put in state 3, children
 * first (the count read once); a node of kind 3 sets bit 7 of its owner's
 * flags */
// NONMATCHING: the kind's load (round 365B, single unit, 20/31, 95 bytes against 97): the base
// keeps it its own instruction (`mov eax, [r14+0x24]; cmp eax, 3`), the build folds it (`cmp dword
// [r14+0x24], 3`); everything before it is the base's
void FUN_0082f070(Node0082f070 *node) /* derived name */
{
    const unsigned count = node->children.size();
    for (unsigned i = 0; i < count; ++i)
        FUN_0082f070(node->children.at(i));
    node->state = 3;
    if (node->kind == 3)
        node->owner->flags |= 0x80;
}

void FUN_0082de80(Node0082f070 *node); /* derived name: not traced */

void FUN_00c55dd0(Owner0082f070 *owner, void *unknown, int flag); /* derived name: not traced */

/* derived names: every node under the node first (the children walked from
 * the first to the end taken once), then the node itself to FUN_0082de80;
 * an owner whose flag bit 0 is clear is then handed to FUN_00c55dd0 with
 * the pointer at +0x108 of the object at 0x5938c40 */
void FUN_0082de00(Node0082f070 *node) /* derived name */
{
    for (Node0082f070 *const *child = node->children.begin(), *const *end = node->children.end();
         child != end; ++child)
        FUN_0082de00(*child);
    FUN_0082de80(node);
    if (!(node->owner->flags & 1))
        FUN_00c55dd0(node->owner, D_5938c40->world, 0);
}
