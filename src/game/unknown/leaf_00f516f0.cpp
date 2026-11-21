/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_object00c1b7f0.h"

/* FUN_00f516f0: the array's append over the registry's entries (an object
 * and the name it was made for; tlg_game_object00c1b7f0.h), called from ten
 * sites (0xf321bf to 0xfe6059, FUN_00fc5680 among them); the block grown by
 * half the count plus one, at most 0x40000 elements a step */
template void Array05943280<Entry00f516f0>::push(const Entry00f516f0 &);
