/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_vector.h"
#include "tlg_game_creation.h"

/* derived names: FUN_00cb73c0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then makes the creation lock D_59458a4
 * (tlg_game_creation.h), which this unit defines free (its constructor's
 * store of 0, last). */

Lock059458a4 D_59458a4;
