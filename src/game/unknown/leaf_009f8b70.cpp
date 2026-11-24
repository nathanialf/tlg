/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: from `node` up through its parents (+0x38), the first node
 * of the type the pointer at 0x5948b00 holds (or one derived from it) that
 * has a component of the type the pointer at 0x581f030 holds; that
 * component, found under the node's reader count, or null. */
extern Type00503fb0 *D_5948b00; /* derived name: the node's type */
extern Type00503fb0 *D_581f030; /* derived name: the component's type */

// NONMATCHING: 0.57: the base keeps the result in r14 across the parents' loop (`xor r14d, r14d` in
// the entry and again before the loop, `mov r14, rcx` when found) where this build returns from rax;
// a loop on `node && !found` is further off (round 573D)
Component00503fb0 *FUN_009f8b70(Object016b85e0 *node) /* derived name */
{
    for (; node; node = node->parent) {
        if (node->isKindOf(D_5948b00)) {
            if (Component00503fb0 *component = node->component(D_581f030))
                return component;
        }
    }
    return 0;
}
