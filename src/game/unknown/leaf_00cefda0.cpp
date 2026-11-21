/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

struct Object016b9958; /* derived name */

/* derived names: the type the node must be of, and the type the class's
 * own objects have (its creator leaves the record at 0x5946900 for the root
 * class's constructor) */
extern const Type00503fb0 *D_598a9f0;
extern const Type00503fb0 *D_5946900;

/* derived names: slot 5 of the vtable at 0x16b9958 (a body of its own where the
 * base class's is FUN_000058a0, `mov eax, 1; ret`): 1 when the node is of the
 * type at 0x598a9f0 and holds no component of the class's own type, else 0. The
 * object itself is not read. */
// NONMATCHING: the readers' count released on each way out (three `lock dec` in the base, the found component
// tested after its own; the build has one release block, the test before it) and the count's address kept in
// a register (`lea r14, [r15+0x30]`) where the base folds it into each `lock dec`
int FUN_00cefda0(Object016b9958 *, Node00503fb0 *node) /* derived name */
{
    if (!node->isKindOf(D_598a9f0))
        return 0;
    return node->findComponent(D_5946900) == 0;
}
