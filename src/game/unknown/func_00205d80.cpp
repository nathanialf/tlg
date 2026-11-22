/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00205d80 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then, in this order, 2 names from
 * strings, each registered with Name's destructor (0x1331800); an empty
 * counted reference that other functions replace by compare-and-swap
 * (0x1bd010, 0x1fb830, 0x2054d0); each reference registered with its
 * destructor (0x1346b00). */

extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_57c9db0(D_15cb5dd, false);
Name D_57c9db4(D_15cb5e6, false);
AtomicRef0045c470<Object016b9108> D_57c9c80;
