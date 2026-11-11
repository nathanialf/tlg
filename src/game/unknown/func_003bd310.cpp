/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_003bd310 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 4 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_003bd310): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_15680e4[9];
extern const char D_15ca420[7];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_57d16f0(D_15ca420, false);
Name D_57d16f4(D_15cb5dd, false);
Name D_57d16f8(D_15cb5e6, false);
/* derived name: a vector of the file's own (pool 0x152b2c0) */
static const Vector4 D_57d15d0(12.0f, 1e+01f, 12.0f, 1.0f);
/* derived name: a vector of the file's own (pool 0x152b2d0) */
static const Vector4 D_57d15e0(0.01f, 1e+01f, 0.01f, 1.0f);
Name D_57d15f0(D_15680e4);
