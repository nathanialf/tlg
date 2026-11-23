/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00d7ef30: equal in the module but for its first registration's target: the base hands atexit 0x134f620, the array's own destructor (rowed as Array05943280's D2); the module emits Array01343a80's complete destructor as a function of its own (0x169 bytes, the array's destructor inlined), which no row places (the layout refuses it, round 523D's gate). */
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00d7ef30 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then, in this order, an array of
 * counted references with its lock (tlg_game_array01343a80.h), registered
 * with the array's destructor (0x134f620; 0xd3b1c0 and 0xd7e590 take the
 * lock at 0x598a004), and an empty counted reference that other functions
 * replace by compare-and-swap (0xc3e720, 0xc4cc70), registered with its
 * destructor (0x1346b00). */
Array01343a80<Ref00503fb0<Object016b9108>> D_5989ff0;
AtomicRef0045c470<Object016b9108> D_598a018;
