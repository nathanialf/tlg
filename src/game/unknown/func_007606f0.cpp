/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_007606f0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 4 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_007606f0): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_15945c4[20];
extern const char D_1594984[13];
extern const char D_15a2beb[17];
extern const char D_15ca367[8];

Name D_5817364(D_15a2beb, false);
Name D_5817360(D_15ca367, false);
Name D_5817368(D_15945c4, false);
Name D_581736c(D_1594984, false);
