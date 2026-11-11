/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_0096a490 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 5 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_0096a490): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_15b6d8e[16];
extern const char D_15b6d9e[15];
extern const char D_15b6dad[15];

Name D_5821a10(D_15b6d9e);
Name D_5821a14(D_15b6d9e);
Name D_5821a18(D_15b6d8e);
Name D_5821a1c(D_15b6dad);
Name D_5821a20(D_15b6dad);
