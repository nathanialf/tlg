/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: FUN_01344d90 empties an array of Names and makes its
 * capacity the size it is given (tlg_game_array.h's clear(unsigned): each
 * Name released in turn, the block read again for each), out of line: the
 * array's own member, instantiated here until a caller of it is written
 * (FUN_00a27850 calls it with 0 for each of four arrays, FUN_00464d20 and
 * FUN_004bb5f0 call it too). */
template void Array05943280<Name>::clear(unsigned);
