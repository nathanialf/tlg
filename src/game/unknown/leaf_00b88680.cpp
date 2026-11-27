/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: slot 5 of the vtable at 0x16b70b0 (Object016b70b0's,
 * tlg_game_object016b70b0.h): true when the node has a component of
 * neither the type the pointer at 0x5835f18 holds nor the one at 0x5835f20
 * (the class's own, leaf_00b87da0.cpp registers it), each searched under
 * the node's reader count. The object itself is not read; a free function
 * here, as FUN_009f6bc0's body (leaf_009f6bc0.cpp, the same shape). */
class Object016b70b0;

extern Type00503fb0 *D_5835f18;       /* derived name */
extern const Type00503fb0 *D_5835f20; /* derived name */

// NONMATCHING: FUN_009f6bc0's residual (205 against 223 bytes; the twins by shape): the base drops the
// first search's count through one folded `lock dec [r15+0x30]` with "none found" in al and the
// second's by hand on each exit; component() for the first search gives the same bytes (round 588D)
int FUN_00b88680(Object016b70b0 *, Object016b85e0 *node) /* derived name */
{
    return !node->component(D_5835f18) && !node->findComponent(D_5835f20);
}
