/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: the collector's barrier: while it marks, a value stored in
 * a marked object has its own object marked (a string only marked, a fixed
 * string, its length's top bit set, left alone); the call timed */
void FUN_00db9c70(lua_State *s, HksGcObject *parent, const HksObject *value)
{
    HksApiTimer timer(s);
    gcBarrier(s, parent, value);
}
