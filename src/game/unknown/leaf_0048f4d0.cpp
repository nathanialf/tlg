/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

extern const Type00503fb0 *D_581b260; /* derived name */
extern Type00503fb0 *D_5939080;       /* derived name: the node's type */
extern const Name D_57d6b70;          /* derived name */

struct Component0048f4d0 { /* derived name: the found component's view */
    u8 unknown0[0x3c];
    Name name; /* +0x3c: names a node */
};

/* derived names: whether the node's component of the type at 0x581b260
 * names (at +0x3c) a node this thread may use, by a name other than the one
 * at 0x57d6b70; false for no node or no such component */
// NONMATCHING: 260 against 272 bytes: the return's zero (FUN_0046f3d0's class): the base makes the
// zero before the drop (`xor eax, eax; lock dec`) and again in each false exit of the named node's walk,
// the result `setne al` extended once at the join (round 588D)
int FUN_0048f4d0(Object016b85e0 *node) /* derived name */
{
    if (!node)
        return 0;
    Component00503fb0 *found = node->component(D_581b260);
    if (!found)
        return 0;
    const Name &name = reinterpret_cast<Component0048f4d0 *>(found)->name;
    if (!findNamed<Object016b85e0>(name, D_5939080))
        return 0;
    return !(name == D_57d6b70);
}
