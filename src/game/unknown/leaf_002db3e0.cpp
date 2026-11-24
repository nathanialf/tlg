/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: FUN_002db3e0 takes the name at an index out of an array of
 * names, the last one put in its place (tlg_game_array.h's removeSwap, the
 * name's assignment and release in line), out of line: the array's own
 * member, instantiated here. Its answer is not used (Object016b4ce0::remove,
 * FUN_00b16a90). */
template int Array05943280<Name>::removeSwap(unsigned);
