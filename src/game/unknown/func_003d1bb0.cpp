/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_003d1bb0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 2 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_003d1bb0): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_156814d[17];
extern const char D_15ca420[7];

Name D_57d1bf0(D_15ca420, false);
/* derived name: a vector of the file's own (pool 0x152b810) */
static const Vector4 D_57d1c00(0.01f, 1e+01f, 0.01f, 1.0f);
Name D_57d1ad0(D_156814d);
