/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00464af0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 4 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_00464af0): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_15a7f48[15];
extern const char D_15c8db4[7];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_57d5780(D_15cb5dd, false);
Name D_57d5784(D_15cb5e6, false);
Name D_57d562c(D_15c8db4, false);
Name D_57d5630(D_15a7f48, false);
