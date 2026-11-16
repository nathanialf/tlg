/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_libc.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: a node as this function reads it: its Name at +0xc, the
 * flags at +0x16 (read as 16 bits, `movzx r14d, word [rbx+0x16]`), its type
 * at +0x18 and the node above it at +0x38 */
struct Node008eb530 { /* derived name */
    u8 unknown0[0xc];
    Name name; /* +0xc */
    u8 unknown10[0x6];
    u16 flags16;              /* +0x16 */
    const Type00503fb0 *type; /* +0x18 */
    u8 unknown20[0x18];
    Node008eb530 *parent; /* +0x38 */
};

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
// NONMATCHING: 47/135 under --module: the thread flag's shape B (cookbook 1704, 2127): the base
// loads the node's flags as 16 bits above the flag's address (`movzx r14d, word [rbx+0x16]`, the
// child's Name spilled to [rbp-0xb8] for it), then `test r14b, 4; jne`, `mov al, [rax]; xor al, 1;
// test al, 1; jne`; the build takes the flag's address first and tests both in memory (`test byte
// [rbx+0x16], 4; jne; test byte [rax], 1; je`). The rest follows from the frame (round 352B)
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
    for (Node008eb530 *node = findNamed<Node008eb530>(child, D_5939080); node;
         node = node->parent) {
        if (node->name == parent) {
            found = true;
            break;
        }
    }
    pushBoolean(state, found);
    return 1;
}
