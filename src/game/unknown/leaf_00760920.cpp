/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted00760920.h"

/* FUN_00760920: the array of counted references to
 * tlg_game_counted00760920.h's class has its append (tlg_game_array.h's
 * push; the growth is the header's) as a function of its own in the
 * executable: the member instantiated here. The body is FUN_001b59d0's byte
 * for byte. Called from 11 sites in 6 functions (FUN_013b7610, FUN_013b7920, FUN_0075d990, FUN_0075de10, FUN_0075e570, FUN_009fa9f0). */
template void
Array05943280<Ref00503fb0<Counted00760920>>::push(const Ref00503fb0<Counted00760920> &);
