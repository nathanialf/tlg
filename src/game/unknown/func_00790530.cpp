/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00790530 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 4 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_00790530): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_1595594[16];
extern const char D_15955a4[13];
extern const char D_15955b1[8];
extern const char D_15955b9[10];

Name D_5818360(D_1595594, false);
Name D_5818340(D_15955a4, false);
Name D_5818344(D_15955b1, false);
Name D_5818480(D_15955b9, false);
