/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00316d90 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 7 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_00316d90): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_15647ed[13];
extern const char D_15647fa[14];
extern const char D_1566741[11];
extern const char D_156674c[9];
extern const char D_15ca420[7];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_57cd370(D_15ca420, false);
Name D_57cd374(D_15cb5dd, false);
Name D_57cd378(D_15cb5e6, false);
Name D_57cd22c(D_1566741, false);
Name D_57cd238(D_156674c, false);
Name D_57cd230(D_15647ed, false);
Name D_57cd234(D_15647fa, false);
