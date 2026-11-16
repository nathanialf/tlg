/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d3ad0.h"

/* FUN_00f66e00 (D1), FUN_00f66ef0 (D0): tlg_game_object016d3ad0.h; the base
 * class's inline destructor (FUN_013d65a0, FUN_013d6640) is emitted with them */
// NONMATCHING: the deleting destructor FUN_00f66ef0 calls the complete one
// where the base inlines it (5/62): the destructor wants the inline hint, with
// slot 2 (FUN_00f66fd0, at the next address) as the class's key function, which
// needs the base's slot 2 (FUN_013d4610, inline in the linkonce stretch) written.
Object016ca148::~Object016ca148() {}
