/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the first component of the type the pointer at 0x5948180
 * holds in the tree under `node`: the node's own first (under its reader
 * count), else the first found in each child's tree in turn; null when none. */
extern Type00503fb0 *D_5948180; /* derived name */

// NONMATCHING: 151 bytes against 154: the base carries the node's own null result into the children's
// loop (`mov rcx, rax` at 0xe64c44, `mov rax, rcx` at each exit, `mov ecx, 0` after a null child)
// where this build makes the exit's 0 a constant; a loop with a break after the test is further
// off (round 573D)
Component00503fb0 *FUN_00e64be0(Object016b85e0 *node) /* derived name */
{
    Component00503fb0 *found = node->component(D_5948180);
    for (unsigned i = 0; !found && i < node->childCount; ++i)
        found = FUN_00e64be0(node->childAt(i));
    return found;
}
