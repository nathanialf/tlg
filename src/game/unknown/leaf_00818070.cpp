/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted00818070.h"

/* FUN_00818070: the array of counted references to
 * tlg_game_counted00818070.h's class has its append (tlg_game_array.h's
 * push; the growth is the header's) as a function of its own in the
 * executable: the member instantiated here. The body is FUN_001b59d0's byte
 * for byte. Called from 8 sites in 6 functions (FUN_008125d0, FUN_0086bb20,
 * FUN_009520e0, FUN_00d37e50, FUN_013bc9f0, FUN_013b7160). */
template void
Array05943280<Ref00503fb0<Counted00818070>>::push(const Ref00503fb0<Counted00818070> &);
