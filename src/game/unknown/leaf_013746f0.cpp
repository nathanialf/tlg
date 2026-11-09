/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_multibase.h"

/* derived names: the int at +0x20, its mask unused; slot 6 of the vtable at
 * 0x16b0cf0, where the body is the library's FUN_00004340 (folded), and through
 * the thunk 0x13746f0 (this - 0x28) the one slot of the base at +0x28 in 19
 * vtables. Only the thunk is claimed here. */
int Class137ba70::FUN_00004340(int) const
{
    return flags;
}
