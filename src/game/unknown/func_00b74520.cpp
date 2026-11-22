/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_creation.h"
#include "tlg_game_node.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00b74520 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then a lock at 0x58354b4 (taken at
 * 0xb7351f) and the array of counted references at 0x58354c0 with its own
 * lock, destroyed by the array's destructor (0x134f620). */
Lock059458a4 D_58354b4;
// NONMATCHING: the bytes are equal, but the destructor registered is Array01343a80's D1,
// which the base folds into its base class's (0x134f620, the row
// _ZN13Array05943280I11Ref00503fb0I14Object016b9108EED1Ev): no row resolves it.
Array01343a80<Ref00503fb0<Object016b9108>> D_58354c0;
