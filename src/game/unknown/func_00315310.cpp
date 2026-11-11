/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00315310 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 11 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_00315310): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_15646bf[30];
extern const char D_1565a3d[7];
extern const char D_1570b4e[10];
extern const char D_15a5ce3[12];
extern const char D_15be169[5];
extern const char D_15c6d3c[6];
extern const char D_15c6d42[16];
extern const char D_15c83d7[6];
extern const char D_15ca420[7];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_57cd220(D_15ca420, false);
Name D_57cd224(D_15cb5dd, false);
Name D_57cd228(D_15cb5e6, false);
Name D_57cc6d0(D_15be169, false);
Name D_57cc6d4(D_1565a3d, false);
Name D_57cc6d8(D_15c83d7, false);
Name D_57cd0c8(D_1570b4e, false);
Name D_57cd0cc(D_15a5ce3, false);
Name D_57cd0f0(D_15c6d3c, false);
Name D_57cd0f4(D_15c6d42, false);
Name D_57cd0d0(D_15646bf, false);
