/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_004aa8c0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then one empty name (index 0), registered with
 * Name's destructor (0x1331800). */

// NONMATCHING: the file's initializer (FUN_004aa8c0): the base sets up the
// empty name's registration first, before the constants, with no frame (345
// bytes against 337).
Name D_57d7338;
