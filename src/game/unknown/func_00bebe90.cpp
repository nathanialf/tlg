/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00bebe90 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (0x58b65f0 to 0x58b6710, config/header_statics.base.txt), then two names
 * looked up without interning (`xor ecx, ecx`), "markers" and
 * "layerMarkers", each registered with Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_00bebe90): the x mask's store is
// `vmovdqa` in this build where the base has `vmovaps` (the movd-domain
// class), and the last name's index store and `lea rsi` before the tail
// call to __cxa_atexit are in the other order.
extern const char D_15b8035[8];
extern const char D_15b0e2c[13];

Name D_58b65e8(D_15b8035, false);
Name D_58b65ec(D_15b0e2c, false);
