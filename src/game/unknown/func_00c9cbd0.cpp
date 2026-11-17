/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_vector.h"
#include "tlg_game_creation.h"

/* derived names: FUN_00c9cbd0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then makes the spin lock at 0x593b138
 * (taken and given back by FUN_00c9aac0) free (its constructor's store of 0,
 * last). */

Lock059458a4 D_593b138; /* derived name */
