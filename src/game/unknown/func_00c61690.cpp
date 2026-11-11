/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00c61690 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 6 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_00c61690): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_14c33e2[6];
extern const char D_15b2aac[5];
extern const char D_15b2ab1[9];
extern const char D_15b2aba[9];
extern const char D_15b2ac3[6];
extern const char D_15c7e60[8];

Name D_5939584(D_15b2aac, false);
Name D_5939588(D_15c7e60, false);
Name D_5939578(D_15b2ab1, false);
Name D_5939574(D_15b2aba, false);
Name D_593957c(D_15b2ac3, false);
Name D_5939580(D_14c33e2, false);
