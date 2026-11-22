/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_cell.h"
#include "tlg_game_node.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00a63b80 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h and the pairs of
 * tlg_game_float2.h and tlg_game_cell.h into the file's own copies
 * (config/header_statics.base.txt), then an empty counted reference that
 * other functions replace by compare-and-swap (0xa5d530, 0xa5e250, 0xa5e3a0,
 * 0xa5ebe0, 0xa5ede0, 0xb62340), registered with its destructor
 * (0x1346b00). */

AtomicRef0045c470<Object016b9108> D_5827ee8;
