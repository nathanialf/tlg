/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_0033dd10 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then one name from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_0033dd10): the last name's
// registration is not a tail call (the file's own vector follows it), and
// `lea rsi` (the name) and `lea rdi` (the destructor) before the call to
// __cxa_atexit are in the other order (the parked order class).
extern const char D_15ca420[7];

Name D_57ce480(D_15ca420, false);
/* derived name: a vector of the file's own (pool 0x1529650) */
static const Vector4 D_57ce1d0(0.01f, 1e+01f, 0.01f, 1.0f);
