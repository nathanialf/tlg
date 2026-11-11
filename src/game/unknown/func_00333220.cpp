/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00333220 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 9 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_00333220): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_1565852[11];
extern const char D_156585d[7];
extern const char D_1565864[15];
extern const char D_1565873[6];
extern const char D_156b0e5[8];
extern const char D_15ca420[7];
extern const char D_15cb0f3[13];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_57cdfb0(D_15ca420, false);
Name D_57cdfb4(D_15cb5dd, false);
Name D_57cdfb8(D_15cb5e6, false);
Name D_57cdfbc(D_15cb0f3);
Name D_57cde70(D_1565852);
Name D_57cde74(D_156585d);
Name D_57cde78(D_156b0e5);
Name D_57cde7c(D_1565864);
Name D_57cdfc0(D_1565873);
