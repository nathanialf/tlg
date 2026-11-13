/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: passes a counted reference to its argument, held for the
 * call, to FUN_00ce2500 with the member at +0xb0 of the object the
 * pointer at 0x5938c40 holds. The classes are not traced. */
struct Member05938c40_b0; /* derived name */

struct Object05938c40 { /* derived name */
    u8 unknown0[0xb0];
    Member05938c40_b0 *unknownb0; /* +0xb0 */
};

extern Object05938c40 *D_5938c40;

void FUN_00ce2500(Member05938c40_b0 *member,
                  const Ref00503fb0<Node00503fb0> &reference); /* derived name */

// NONMATCHING: 8/63, 220 bytes for 231: after the call the base drops the
// reference through the argument it kept in r15 and makes the call in two
// places, one for a null argument; the build reads the reference back from
// its stack slot, since the callee is a stand-in here and may write it. The
// callee's body in the module would say that it does not.
void FUN_00cebe40(Node00503fb0 *node) /* derived name */
{
    FUN_00ce2500(D_5938c40->unknownb0, Ref00503fb0<Node00503fb0>(node));
}
