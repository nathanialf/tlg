/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00773e90 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 10 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_00773e90): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_15948c5[9];
extern const char D_15948ce[26];
extern const char D_15948e8[18];
extern const char D_15948fa[34];
extern const char D_159491c[29];
extern const char D_1594939[23];
extern const char D_1594950[24];
extern const char D_1594968[28];
extern const char D_1594984[13];
extern const char D_1595794[18];

Name D_58178ac(D_1595794, false);
Name D_5817900(D_15948c5, false);
Name D_5817908(D_15948ce, false);
Name D_5817904(D_15948e8, false);
Name D_581790c(D_15948fa, false);
Name D_5817910(D_159491c, false);
Name D_5817918(D_1594939, false);
Name D_581791c(D_1594950, false);
Name D_5817920(D_1594968, false);
Name D_5817914(D_1594984, false);
