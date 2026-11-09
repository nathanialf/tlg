/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

#include "tlg_game_multibase.h"

/* derived names: clears bits 4 and 5 of the int at +0x20; slot 5 of the
 * vtables from 0x16b0c50 and, through the thunk 0x13746d0 (this - 0x30, the
 * body inlined into it), slot 1 of the base at +0x30. Class16b57c0 has the
 * same body (FUN_00b386b0). */
void Class137ba70::FUN_0137ba50()
{
    flags &= ~0x30;
}
