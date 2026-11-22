/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0134f620.h"

/* FUN_0138e360: the array of counted references
 * (tlg_game_object0134f620.h) has its append (called at 101 sites, the new
 * element's index returned) as a function of its own in the executable:
 * the member instantiated here. The append of another array's elements,
 * FUN_013a6db0, calls it once for each element. */
template unsigned
Array05943280<Ref00503fb0<Object016b9108>>::add(const Ref00503fb0<Object016b9108> &);
