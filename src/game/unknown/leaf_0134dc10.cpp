/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016c76a0.h"

/* derived names: the complete destructor of Object016c76a0
 * (tlg_game_object016c76a0.h), FUN_0134dc10: the body is empty, the
 * members are released in reverse order and the base's destructor is a
 * tail call. */
// NONMATCHING: the deleting destructor FUN_0134dd20: the base inlines this complete destructor into it (268 bytes);
// the build calls it. Measured in round 476D: as an implicit destructor (hinted, limit 325) it costs 335 at the unit
// stage, the array of Names' destructor 215 of it and the Name's 45; with Name's destructor a call it costs 245
// and the deleting one holds it, but that form loses 60 rows elsewhere
Object016c76a0::~Object016c76a0() {}
