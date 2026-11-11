/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_01249ca0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 5 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_01249ca0): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_15c99df[38];
extern const char D_15c9a05[17];
extern const char D_15c9a16[39];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad7ae0(D_15cb5dd, false);
Name D_5ad7ae4(D_15cb5e6, false);
Name D_5ad79ac(D_15c99df, false);
Name D_5ad7ae8(D_15c9a05, false);
Name D_5ad79f0(D_15c9a16, false);
