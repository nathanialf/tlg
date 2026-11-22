/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b64f8.h"

/* 0xb4b060: slot 8 first (inlined by the link), then the pool given up,
 * its word at +0x48 reset first; the Names and the reference released,
 * then the base's destructor as a tail call. The destructor is the class's
 * key function, so this file emits the vtable. */
Object016b64f8::~Object016b64f8()
{
    FUN_00b4b950(this);
    pool.resetAndShutdown();
}
