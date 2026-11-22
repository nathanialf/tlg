/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_type.h"
#include "tlg_hks.h"
#include "tlg_game_object016b85e0.h"

/* derived name: the type the pointer at 0x5939080 holds (the node is passed
 * on only when its type is this one or derives from it) */
extern Type00503fb0 *D_5939080;

/* derived name: takes a node of that type, or null; not traced */
void FUN_008e1d10(Object016b85e0 *node);

/* derived name: a script function: the node its first argument names, when
 * this thread may use it, is held by a counted reference while FUN_008e1d10
 * is given it (null unless its type is the one at 0x5939080 or derives from
 * it); returns no values */
// NONMATCHING: the type test is a branch per outcome here; the base keeps
// it a flag (`mov dl, 1` in the loop, `xor edx, edx` on a match) and picks
// the argument with `test dl, dl; cmove rdi, rbx` before one call.
int FUN_008d6590(lua_State *state) /* derived name */
{
    HashedString string;
    FUN_00e81bd0(&string, state, 1);
    Name name(string);
    Object016b85e0 *node = static_cast<Object016b85e0 *>(D_17ac870[name.index].record18);
    if (node && ((node->flags16 & 4) || threadMayUse())) {
        Ref00503fb0<Object016b85e0> held(node);
        FUN_008e1d10(node->isKindOf(D_5939080) ? node : 0);
    }
    return 0;
}
