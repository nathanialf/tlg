/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00a27fa0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then, in this order, 8 names from
 * strings, each registered with Name's destructor (0x1331800); an empty
 * counted reference that other functions replace by compare-and-swap
 * (0x1b2ff0, 0x1db8b0, 0x1f4f10, 0x2a5810, 0x2a5950, 0x3fd0a0, 0x43c7b0,
 * 0x881ef0, 0xa1bdd0, 0xa26c10, 0xa27260, 0xa27400, 0xa27ad0, 0x138b160);
 * each reference registered with its destructor (0x1346b00). */

extern const char D_15a41b7[9];
extern const char D_15a41c0[9];
extern const char D_15a41c9[9];
extern const char D_15a41d2[16];
extern const char D_15a41e2[5];
extern const char D_15a41e7[5];
extern const char D_15a41ec[5];
extern const char D_15c94db[5];

Name D_58272d0(D_15a41b7, false);
Name D_58272d4(D_15a41c0, false);
Name D_58272d8(D_15a41c9, false);
Name D_58272dc(D_15a41d2, false);
Name D_58272e0(D_15a41e2, false);
Name D_58272e4(D_15c94db, false);
Name D_58272e8(D_15a41e7, false);
Name D_58272ec(D_15a41ec, false);
AtomicRef0045c470<Object016b9108> D_5827190;
