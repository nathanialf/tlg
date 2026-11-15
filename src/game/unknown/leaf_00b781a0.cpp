/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b6c98.h"

/* derived name: the complete destructor: the body is empty; the reference
 * at +0x70 is released, then the base's destructor is inlined (its vptr
 * store, its reference at +0x60, then Object016b9108's). FUN_00b78340, slot
 * 1, is the deleting one and calls it. The destructor is the class's key
 * function, so this file emits the vtable. */
Object016b6c98::~Object016b6c98() {}
