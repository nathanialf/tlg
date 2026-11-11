/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00503360 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 11 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_00503360): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_157057c[18];
extern const char D_157058e[31];
extern const char D_15705ad[31];
extern const char D_15abfbb[7];
extern const char D_15c627c[41];
extern const char D_15c62a5[40];
extern const char D_15cb21f[8];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_57d9e60(D_15c627c);
Name D_57d9e64(D_15c62a5);
Name D_57d9e68(D_15cb5dd, false);
Name D_57d9e6c(D_15cb5e6, false);
Name D_57d9e70;
Name D_57d9e74(D_15cb21f);
Name D_57d9e78(D_15cb5dd, false);
Name D_57d9e7c(D_15abfbb, false);
Name D_57d9e80(D_157057c, false);
Name D_57d9e84(D_157058e, false);
Name D_57d9e88(D_15705ad, false);
