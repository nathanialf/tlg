/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: slot 5 of the vtable at 0x16b70b0, FUN_009f6bc0's body
 * (leaf_009f6bc0.cpp) over two other types: true when the node has a
 * component of neither the type the pointer at 0x5835f18 holds nor the one
 * at 0x5835f20 (or of one derived from either), each searched under the
 * node's reader count. The object itself is not read. */
class Object016b70b0;

extern const Type00503fb0 *D_5835f18; /* derived name */
extern const Type00503fb0 *D_5835f20; /* derived name */

// NONMATCHING: FUN_009f6bc0's residual (leaf_009f6bc0.cpp), the second search's exits
int FUN_00b88680(Object016b70b0 *, Object016b85e0 *node) /* derived name */
{
    return !node->component(D_5835f18) && !node->hasComponent(D_5835f20);
}
