/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00f84b30 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 5 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_00f84b30): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_15c5687[10];
extern const char D_15c5691[17];
extern const char D_15c56a2[22];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5aceda0(D_15cb5dd, false);
Name D_5aceda4(D_15cb5e6, false);
Name D_5acecb4(D_15c5687, false);
Name D_5acecb0(D_15c5691, false);
Name D_5acec50(D_15c56a2, false);
