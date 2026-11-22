/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_command003e4440.h"

/* FUN_003e4440: the array of counted references to commands
 * (tlg_game_command003e4440.h) has its append (tlg_game_array.h's push; the
 * growth is the header's) as a function of its own in the executable: the
 * member instantiated here. The body is FUN_001b59d0's byte for byte.
 * Called from 13 sites in 13 functions (FUN_003e12d0 to FUN_003e38e0), each
 * forming the array's address at +0x450 of its object. */
template void
Array05943280<Ref00503fb0<Command003e4440>>::push(const Ref00503fb0<Command003e4440> &);
