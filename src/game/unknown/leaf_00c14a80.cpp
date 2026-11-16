/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: FUN_00c14a80 puts a value before the first element of an
 * array of ints (tlg_game_array.h's pushFront), out of line: the array's own
 * member, instantiated here until a caller of it is written. Its caller
 * (0xd4be0b, 0xd4be83) walks a chain of indices that ends at -1, putting
 * each before the ones it has. The same body as FUN_006e0240 over floats. */
template void Array05943280<int>::pushFront(const int &);
