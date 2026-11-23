/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00a01a80: the constructor's three dword stores at +0x8, +0xc and +0x10 (0, 4, 0) stay three in the base (0xa01a99 to 0xa01aad); the build joins the first two into one 8-byte store (DAGCombiner MergeConsecutiveStores), the class of stores to a global noted in round 523D. */
#include "tlg_game_object016cdff0.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00a01a80 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then the list of 1024 named values
 * (tlg_game_object016cdff0.h), registered with its destructor (0x1388570).
 * FUN_001db8b0 and FUN_0069d690 take its address (neither written). */
Object016cdff0 D_5824208;
