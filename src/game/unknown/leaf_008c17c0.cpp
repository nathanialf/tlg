/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b01f0.h"

/* derived name: the complete destructor: the body is empty; the Names are
 * released, last first, then the base's destructor is inlined (its vptr
 * store, its two Names, then Object016b9108's). FUN_008c1920, slot 1, is the
 * deleting one and calls it. The destructor is the class's key function, so
 * this file emits the vtable. */
Object016b01f0::~Object016b01f0() {}
