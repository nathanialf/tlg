/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_type.h"
#include "tlg_hks_string.h"

/* derived name: a script function: called with one argument, the name of
 * the type of the node the argument names, when this thread may use the
 * node, as a string (nil when the type's name has no string); nil
 * otherwise. Returns one value. */
// NONMATCHING: the blocks are the base's; the frame is 0x18 bytes here and
// 0x28 in the base (16 bytes the base keeps and never addresses), the
// frame's top is kept from the count for the nil (the base reads it again),
// and the guard's pointer and the state trade rbx and r12.
int FUN_00e73a30(lua_State *state) /* derived name */
{
    if (argumentCount(state) == 1) {
        HashedString string;
        FUN_00e81bd0(&string, state, 1);
        Name name(string);
        Node00503fb0 *node = static_cast<Node00503fb0 *>(D_17ac870[name.index].record18);
        if (node && ((node->flags16 & 4) || threadMayUse())) {
            pushString(state, D_17ac870[node->type->name.index].string0);
            return 1;
        }
    }
    pushNil(state);
    return 1;
}
