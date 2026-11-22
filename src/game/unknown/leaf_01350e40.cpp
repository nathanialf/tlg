/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_simd.h"

/* FUN_01350e40: another array's vectors appended (called by FUN_004477a0):
 * room made for both counts, then each vector appended by one aligned
 * move, the append inlined */
template void Array05943280<Vec4>::append(const Array05943280<Vec4> &);
