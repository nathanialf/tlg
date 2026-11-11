/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00ad8990 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 4 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_00ad8990): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_15a8e66[18];
extern const char D_15c627c[41];
extern const char D_15c62a5[40];
extern const char D_15c640a[18];

Name D_582d490(D_15c627c);
Name D_582d494(D_15c62a5);
Name D_582d3a0(D_15c640a, false);
Name D_582d370(D_15a8e66, false);
