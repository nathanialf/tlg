/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_multibase.h"

/* derived names: clears bits 4 and 5 of the int at +0x20; slot 5 of the vtable
 * at 0x16b57c0 and, through the thunk 0xb386c0 (this - 0x30), slot 1 of the
 * base at +0x30. */
void Class16b57c0::FUN_0137ba50()
{
    flags &= ~0x30;
}
