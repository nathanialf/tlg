/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00236e70 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 4 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_00236e70): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_156a0c9[12];
extern const char D_15c627c[41];
extern const char D_15c62a5[40];
extern const char D_15ca420[7];

Name D_57caa40(D_15ca420, false);
Name D_57caa44(D_15c627c);
Name D_57caa48(D_15c62a5);
Name D_57ca848(D_156a0c9, false);
