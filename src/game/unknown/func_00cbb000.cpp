/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the unit of FUN_00cbb000 (not written yet), which clears
 * this thread's flag D_16dc098 (`mov byte [rax], 0` at 0xcbb0b1, one of the
 * flag's two stores; the other, of 1, is FUN_00e95140's) after registering
 * two names. The flag's reader is defined here, beside its writer. Its body
 * has no address in the executable: every call was inlined by the link and
 * the copy discarded (of the 16,223 functions of the game's one CIE run, 2
 * have no reference of any kind). */
bool threadMayUse() /* derived name */
{
    return D_16dc098;
}
