/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: FUN_006e0240 puts a value before the first element of an
 * array of floats (tlg_game_array.h's pushFront), out of line: the array's
 * own member, instantiated here until a caller of it is written. Its callers
 * (0x6dc223, 0x6dd48c, 0x6dd499, 0x6dd4ad) keep three such arrays at +0x38,
 * +0x68 and +0x80 of one object, and the floats they fill are read with
 * `vmovss`. */
template void Array05943280<float>::pushFront(const float &);
