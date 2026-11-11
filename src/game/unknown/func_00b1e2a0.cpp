/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00b1e2a0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 4 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_00b1e2a0): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_15abf5d[23];
extern const char D_15abf74[29];
extern const char D_15abf91[16];
extern const char D_15b1dea[7];

Name D_5832b0c(D_15abf5d, false);
Name D_5832b14(D_15abf74, false);
Name D_5832b18(D_15b1dea, false);
Name D_5832b10(D_15abf91, false);
