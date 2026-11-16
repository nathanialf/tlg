/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_value01351240.h"

/* derived names: FUN_01351240 takes the element at an index out of an array
 * of references another thread may replace, the last element put in its
 * place (tlg_game_array.h's removeSwap), out of line: the array's own
 * member, instantiated here. The referenced class is not traced. */
template int Array05943280<AtomicRef0045c470<Value01351240>>::removeSwap(unsigned);
