/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_003dcdb0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 6 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_003dcdb0): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_15681a7[17];
extern const char D_15681b8[23];
extern const char D_15681cf[21];
extern const char D_15ca420[7];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_57d1eb0(D_15cb5dd, false);
Name D_57d1eb4(D_15cb5e6, false);
Name D_57d1eb8(D_15ca420, false);
Name D_57d1d80(D_15681a7);
Name D_57d1d84(D_15681b8);
Name D_57d1da0(D_15681cf);
