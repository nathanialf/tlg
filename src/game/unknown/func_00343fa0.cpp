/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00343fa0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 4 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_00343fa0): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_1565d33[11];
extern const char D_1565d3e[25];
extern const char D_1565d57[26];
extern const char D_15ca420[7];

Name D_57ce8e0(D_15ca420, false);
Name D_57ce7ac(D_1565d33);
Name D_57ce8e4(D_1565d3e);
Name D_57ce8e8(D_1565d57);
