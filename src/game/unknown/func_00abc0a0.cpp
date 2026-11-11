/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00abc0a0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 8 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_00abc0a0): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_15a7807[10];
extern const char D_15a7811[19];
extern const char D_15a7824[20];
extern const char D_15a7838[12];
extern const char D_15a8d8d[7];
extern const char D_15ca420[7];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_582acc0(D_15cb5dd, false);
Name D_582acc4(D_15cb5e6, false);
Name D_582acc8(D_15ca420, false);
Name D_582ab9c(D_15a7807, false);
Name D_582aba0(D_15a7811, false);
Name D_582ab90(D_15a7824, false);
Name D_582ab98(D_15a7838, false);
Name D_582ab94(D_15a8d8d, false);
