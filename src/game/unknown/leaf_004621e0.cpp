/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: over the tree under `node`, the first component of each
 * node of the type the pointer at 0x5948180 holds (found under the node's
 * reader count) has bit 8 of its int at +0x38 cleared when `enable` is true
 * and set when it is false; the children are walked by pointer, their array
 * and count read once. The component's class is not traced. */
extern Type00503fb0 *D_5948180; /* derived name */

struct Flags004621e0 { /* derived name: the component's view */
    u8 unknown0[0x38];
    int flags; /* +0x38 */
};

// NONMATCHING: 206 bytes against 190: the bit is set or cleared by a branch in the base (0x462255:
// `test r14b, r14b; je`, `and` or `or`, one store) where this build selects (`cmove`); CodeGenPrepare
// turns a select into a branch only for a compare with a loaded operand (CodeGenPrepare.cpp:3877-3897
// of 3.7.1), so the base's condition or the flag's update is another form (round 573D)
void FUN_004621e0(Object016b85e0 *node, bool enable) /* derived name */
{
    if (Component00503fb0 *component = node->component(D_5948180)) {
        Flags004621e0 *view = reinterpret_cast<Flags004621e0 *>(component);
        if (enable)
            view->flags &= ~0x100;
        else
            view->flags |= 0x100;
    }
    for (Ref00503fb0<Object016b85e0> *child = node->children, *end = child + node->childCount;
         child != end; ++child)
        FUN_004621e0(child->get(), enable);
}
