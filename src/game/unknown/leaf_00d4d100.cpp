/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

extern const Type00503fb0 *D_5948f08; /* derived name */

/* derived names: the components of the type at 0x5948f08 of a node and of
 * every node under it, appended to the array in that order (depth first,
 * each node's own first); nothing for a null node */
void FUN_00d4d100(Array05943280<Component00503fb0 *> *found,
                  Object016b85e0 *node) /* derived name */
{
    if (!node)
        return;
    if (Component00503fb0 *component = node->component(D_5948f08))
        found->push(component);
    for (unsigned i = 0; i < node->childCount; ++i)
        FUN_00d4d100(found, node->childAt(i));
}
