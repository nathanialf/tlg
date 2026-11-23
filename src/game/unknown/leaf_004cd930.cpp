/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* FUN_004cd930: tlg_game_array.h's addUnique over names, out of line (19
 * callers; FUN_008831f0 tests the set itself first): the names compared by
 * index, the new one's count raised in the name table at 0x17ac870 */
// NONMATCHING: 68/73, the last store only: the base extends the new slot's
// index (`mov ecx, r15d`) after the name's `lock inc`, the build before it
// (the placement address formed first in the IR), FUN_00c149a0's class
template void Array05943280<Name>::addUnique(const Name &);
