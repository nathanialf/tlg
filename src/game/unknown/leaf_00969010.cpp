/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted00969010.h"

/* FUN_00969010: the array of counted references to
 * tlg_game_counted00969010.h's class has its append (tlg_game_array.h's
 * push; the growth is the header's) as a function of its own in the
 * executable: the member instantiated here. The body is FUN_001b59d0's byte
 * for byte. Called from 11 sites in 6 functions (FUN_00963120, FUN_00963260,
 * FUN_00963610, FUN_00963830, FUN_00963950, FUN_00964020). */
template void
Array05943280<Ref00503fb0<Counted00969010>>::push(const Ref00503fb0<Counted00969010> &);
