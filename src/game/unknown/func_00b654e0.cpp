/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_cell.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00b654e0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h and the pairs of
 * tlg_game_float2.h and tlg_game_cell.h into the file's own copies
 * (config/header_statics.base.txt), then, in this order, 7 names from
 * strings, each registered with Name's destructor (0x1331800); a pair of
 * floats, 380 and 170 (0xa5e3a0 reads it and this unit's 960 by 540 pair);
 * an empty counted reference that other functions replace by
 * compare-and-swap (0x1db8b0, 0xa5ede0, 0xb611a0), registered with its
 * destructor (0x1346b00). */

extern const char D_15ae0f9[19];
extern const char D_15ae10c[19];
extern const char D_15ae11f[19];
extern const char D_15ae132[21];
extern const char D_15ae147[17];
extern const char D_15ae158[26];
extern const char D_15ae172[24];

Name D_5834474(D_15ae0f9, false);
Name D_5834478(D_15ae10c, false);
Name D_583447c(D_15ae11f, false);
Name D_5834480(D_15ae132, false);
Name D_5834484(D_15ae147, false);
Name D_5834488(D_15ae158, false);
Name D_583448c(D_15ae172, false);
Float2 D_58344b4(380.0f, 170.0f);
AtomicRef0045c470<Object016b9108> D_5834440;
