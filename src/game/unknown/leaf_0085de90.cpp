/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the Name at +0x60 (FUN_0085de90) or at +0xb4
 * (FUN_0085df80) of the object becomes that of the parent of the node the
 * name names (of the type D_5939080 points to, usable by this thread); FUN_00852180
 * calls one of the two (0x8524d2, 0x8524df) by whether a Name it holds is
 * the one at 0x581d684. The object's class is not traced. */
struct Object0085de90 { /* derived name */
    u8 unknown0[0x60];
    Name name60; /* +0x60 */
    u8 unknown64[0x50];
    Name nameb4; /* +0xb4 */
};

extern const Type00503fb0 *D_5939080; /* derived name: the node's type */

void FUN_0085de90(Object0085de90 *self, const Name &name) /* derived name */
{
    Node00503fb0 *node = findNamed<Node00503fb0>(name, D_5939080);
    if (node)
        self->name60 = node->parent->name;
}

void FUN_0085df80(Object0085de90 *self, const Name &name) /* derived name */
{
    Node00503fb0 *node = findNamed<Node00503fb0>(name, D_5939080);
    if (node)
        self->nameb4 = node->parent->name;
}
