/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0139b6b0.h"

/* The emptying of an array of 160-byte records that each hold a name and a
 * counted reference (tlg_game_object0139b6b0.h): the array's own member, a
 * function of its own in the executable (ten calls in FUN_00729190),
 * instantiated here. */
// NONMATCHING: instruction order only: the base forms the owners' table's address before it
// copies the array's address for the reallocation (`lea rax, [D_5943280]; mov rbx, rdi`), the
// build after it. 100 of 102 equal under --module.
template void Array05943280<Entry0072bbc0>::clear();
