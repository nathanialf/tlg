/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00a99ad0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 6 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_00a99ad0): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_15a6f3f[13];
extern const char D_15a6f4c[38];
extern const char D_15a6f72[38];
extern const char D_15a6f98[38];
extern const char D_15a6fbe[9];
extern const char D_15b3b78[8];

Name D_5829db0(D_15a6f3f);
Name D_5829db4(D_15a6f4c);
Name D_5829db8(D_15a6f72);
Name D_5829dbc(D_15a6f98);
Name D_5829dc0(D_15b3b78);
Name D_5829dc4(D_15a6fbe);
