/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: a virtual slot of a component class (held at 0x16b19a8): true
 * when the node has no component of the type D_58237e8 points to (or of one
 * derived from it). The object itself is not read. Class and method unknown. */
struct Object009f54b0; /* derived name */

extern Type00503fb0 *D_58237e8; /* derived name */

// NONMATCHING: loop form, isKindOf's loop entered at the parent load in the base (its first
// compare before the loop) where the build tests at the header; the index kept `int` with movsxd
// in the base where the build widens it (IndVarSimplify); &readers kept in r14 by the build
bool FUN_009f54b0(Object009f54b0 *, Node00503fb0 *node) /* derived name */
{
    return node->findComponent(D_58237e8) == 0;
}
