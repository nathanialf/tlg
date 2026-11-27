/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

extern const Type00503fb0 *D_5948f08; /* derived name: FUN_00d4d100's type */
extern const Type00503fb0 *D_59453d0; /* derived name */

/* derived names: the components of the type at 0x5948f08 of a node and of
 * every node under it reached through children of the type at 0x59453d0 (or one
 * derived from it), appended to the array depth first, each node's own
 * first (FUN_00d4d100's walk, the children taken by pointer) */
void FUN_00ca31c0(Object016b85e0 *node,
                  Array05943280<Component00503fb0 *> *found) /* derived name */
{
    if (Component00503fb0 *component = node->component(D_5948f08))
        found->push(component);
    Ref00503fb0<Object016b85e0> *child = node->children;
    for (Ref00503fb0<Object016b85e0> *end = child + node->childCount; child != end; ++child) {
        if (child->get()->isKindOf(D_59453d0))
            FUN_00ca31c0(child->get(), found);
    }
}
