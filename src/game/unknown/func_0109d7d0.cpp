/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_0109d7d0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 5 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_0109d7d0): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_15c6d3c[6];
extern const char D_15c6d42[16];
extern const char D_15c6d52[11];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad1240(D_15cb5dd, false);
Name D_5ad1244(D_15cb5e6, false);
Name D_5ad1150(D_15c6d3c, false);
Name D_5ad1154(D_15c6d42, false);
Name D_5ad1248(D_15c6d52, false);
