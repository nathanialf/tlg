/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016cb4b0.h"

/* derived names: the complete destructor of Object016cb4b0
 * (tlg_game_object016cb4b0.h): it stores the vtable, releases the block of
 * its array at +0x248 (tlg_game_array.h; its elements have no destructor),
 * then tail-calls its base's destructor (0x822190). FUN_006708b0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016cb4b0::~Object016cb4b0() {}
