/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_01067d40 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 11 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_01067d40): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_15ca27a[9];
extern const char D_15ca283[10];
extern const char D_15ca28d[10];
extern const char D_15ca367[8];
extern const char D_15caff8[15];
extern const char D_15cb04a[15];
extern const char D_15cb21f[8];
extern const char D_15cb254[8];
extern const char D_15cb266[10];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad0a40(D_15cb5dd, false);
Name D_5ad0a44(D_15cb5e6, false);
Name D_5ad08e0(D_15ca367, false);
Name D_5ad08e4(D_15ca27a, false);
Name D_5ad08e8(D_15ca283, false);
Name D_5ad08ec(D_15ca28d, false);
Name D_5ad08f0(D_15cb266, false);
Name D_5ad08f4(D_15cb04a, false);
Name D_5ad08f8(D_15caff8, false);
Name D_5ad08fc(D_15cb254, false);
Name D_5ad0900(D_15cb21f, false);
