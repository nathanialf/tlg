/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_frames013fb310.h"

/* derived names: FUN_013e71b0 sizes an array of frame sets (24-byte lists,
 * each its own block, count, capacity, owner and lock): the sets destroyed
 * (each block given back in line), the capacity made the size exactly, then
 * each new set built by FUN_013e72e0 (tlg_game_array.h's resize). The
 * array's own member, instantiated here until a caller of it is written:
 * the constructors of the track classes (FUN_013ef390, FUN_014397e0,
 * FUN_01495350 and seventeen more). */
/* OPEN (FINISHING rule 6), checked in round 513D: its callers in the tree declare it under this
 * signature, and the link keeps every call (cost 210, over the link's threshold of 175) */
template void Array05943280<FrameSet00fda5c0>::resize(unsigned);
