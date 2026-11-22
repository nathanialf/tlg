/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b0c28.h"
#include "tlg_game_vector.h"

/* derived names: FUN_009114c0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then an empty counted reference that
 * other functions replace by compare-and-swap (0x1db8b0, 0x90cfa0, 0x90d360,
 * 0x911630, 0x911690), registered with its destructor (0x1346b00), and the
 * static object of the vtable at 0x16b0c28, whose empty destructor is not
 * registered. */

AtomicRef0045c470<Object016b9108> D_58200b0;
Object016b0c28 D_58200b8;
