/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_multibase.h"

/* derived names: sets bits in the int at +0x20; slot 8 of the vtables from
 * 0x16b0c50 and, through the thunk 0x13746e0 (this - 0x30), slot 2 of the
 * base at +0x30. */
void Class137ba70::FUN_0137ba70(int bits)
{
    flags |= bits;
}
