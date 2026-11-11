/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_01212640 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 13 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_01212640): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_15c91d2[10];
extern const char D_15c91dc[10];
extern const char D_15c91e6[20];
extern const char D_15c91fa[19];
extern const char D_15c920d[18];
extern const char D_15c921f[20];
extern const char D_15c9233[19];
extern const char D_15c9246[18];
extern const char D_15c9258[24];
extern const char D_15c9270[23];
extern const char D_15c9287[25];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad7720(D_15cb5dd, false);
Name D_5ad7724(D_15cb5e6, false);
Name D_5ad7610(D_15c91d2, false);
Name D_5ad7614(D_15c91dc, false);
Name D_5ad7728(D_15c91e6, false);
Name D_5ad772c(D_15c91fa, false);
Name D_5ad7730(D_15c920d, false);
Name D_5ad7734(D_15c921f, false);
Name D_5ad7738(D_15c9233, false);
Name D_5ad773c(D_15c9246, false);
Name D_5ad7630(D_15c9258, false);
Name D_5ad7634(D_15c9270, false);
Name D_5ad7650(D_15c9287, false);
