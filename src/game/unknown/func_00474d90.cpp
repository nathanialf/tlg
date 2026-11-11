/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00474d90 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then one name from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_00474d90): the x mask's store is
// `vmovdqa` in this build where the base has `vmovaps` (the movd-domain
// class), and the last name's index store and `lea rsi` before the tail
// call to __cxa_atexit are in the other order.
extern const char D_15a7f27[15];

Name D_57d6134(D_15a7f27, false);
