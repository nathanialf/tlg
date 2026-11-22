/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: FUN_01392310 is the release of an array of counted
 * references (tlg_game_array.h's release(): every reference dropped, the
 * count cleared, the block given back), out of line: the array's own
 * member, instantiated here until a caller of it is written. The counted
 * class is not traced: one over the counted base (tlg_game_object016b9108.h). */
struct Counted01392310 : Counted00c14bc0 { /* derived name */
};

template void Array05943280<Ref00503fb0<Counted01392310>>::release();
