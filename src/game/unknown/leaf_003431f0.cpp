/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_element00343110.h"

/* derived names: FUN_003431f0 is the copy of an array of the elements (tlg_game_array.h's assignment) for
 * the 32-byte elements of tlg_game_element00343110.h, out of line: the
 * array's own member, instantiated here until a caller of it is written. */
// NONMATCHING: 63 of 65, whole module (round 437A): in the reallocation the base reads the
// owner's index (`mov edx, [rbx+0x10]`) before the block (`mov rsi, [rbx]`), the build the
// block first. clear(unsigned) with the owner read into a local first (resize()'s form) makes
// this and FUN_00fbb4b0 equal but loses four rows whose elements have destructors (0x134f620,
// 0x1344d90, 0x1372960, 0x208a00: the base reads the block first there)
template void Array05943280<Element00343110>::operator=(const Array05943280<Element00343110> &);
