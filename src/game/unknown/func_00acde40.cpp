/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00acde40 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 7 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_00acde40): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_15a8020[25];
extern const char D_15a8039[25];
extern const char D_15a8052[25];
extern const char D_15a806b[25];
extern const char D_15bdfea[6];
extern const char D_15be009[5];

Name D_582c604;
Name D_582c614(D_15bdfea, false);
Name D_582c618(D_15be009, false);
Name D_582c600(D_15a8020, false);
Name D_582c608(D_15a8039, false);
Name D_582c60c(D_15a8052, false);
Name D_582c610(D_15a806b, false);
