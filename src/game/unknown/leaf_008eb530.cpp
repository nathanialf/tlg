/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_libc.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"

extern Type00503fb0 *D_5939080; /* derived name: the node's type */

/* derived name: the Name its argument's string makes (interned), the
 * string read through FUN_00e81bd0 */
static inline Name argumentName(lua_State *state, int argument)
{
    HashedString string;
    FUN_00e81bd0(&string, state, argument);
    return Name(string);
}

/* derived names: the script C function named "MSC_IsParent" by its
 * parameter-count message (with the wrong count it formats that message into
 * a local buffer that nothing reads): pushes whether the node the Name its
 * first argument's string makes names (of the type D_5939080 points to, or
 * one derived from it), or one of the nodes above it, has the Name its second
 * argument's string makes, as a boolean; returns 1 (one result). The C
 * function's own name is unknown. */
// NONMATCHING: the reload of the child's Name spilled across the thread flag's address: the base
// reloads it once where the two found paths meet (the found node tested for null first, its
// failure joining the lookup's other failures), the build on each path before the test.
int FUN_008eb530(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 2) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_IsParent", 2);
    }
    Name child = argumentName(state, 1);
    Name parent = argumentName(state, 2);
    bool found = false;
    for (Node00503fb0 *node = findNamed<Node00503fb0>(child, D_5939080); node;
         node = node->parent) {
        if (node->name == parent) {
            found = true;
            break;
        }
    }
    pushBoolean(state, found);
    return 1;
}
