/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00c0a600 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 4 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_00c0a600): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_14cccfe[4];
extern const char D_15b0dcd[7];
extern const char D_15b0dd4[7];
extern const char D_15b8061[7];

Name D_58b7284(D_15b0dcd, false);
Name D_58b7288(D_14cccfe, false);
Name D_58b728c(D_15b8061, false);
Name D_58b7290(D_15b0dd4, false);
