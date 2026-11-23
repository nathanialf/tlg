/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted00351760.h"

/* FUN_00351760: the array of counted references to
 * tlg_game_counted00351760.h's class has its append (tlg_game_array.h's
 * push; the growth is the header's) as a function of its own in the
 * executable: the member instantiated here. The body is FUN_001b59d0's byte
 * for byte. Called from 5 sites in FUN_003496c0, FUN_00823580 and
 * FUN_008239d0. */
template void
Array05943280<Ref00503fb0<Counted00351760>>::push(const Ref00503fb0<Counted00351760> &);
