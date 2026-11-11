/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_008503c0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 2 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_581d180(D_15cb5dd, false);
Name D_581d184(D_15cb5e6, false);
/* derived name: a vector of the file's own (pool 0x1538850) */
static const Vector4 D_581d040(0.0f, 0.0f, 0.0f, 1.0f);
