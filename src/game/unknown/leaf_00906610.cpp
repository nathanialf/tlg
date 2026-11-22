/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted00760920.h"

/* FUN_00906610: the array of counted references to
 * tlg_game_counted00760920.h's first class has its append
 * (tlg_game_array.h's push; the growth is the header's) as a function of
 * its own in the executable: the member instantiated here. The body is
 * FUN_001b59d0's byte for byte. Called from 3 sites in 2 functions
 * (FUN_00905270, FUN_013b7920). */
template void
Array05943280<Ref00503fb0<Counted00906610>>::push(const Ref00503fb0<Counted00906610> &);
