/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_compiler00da5b20.h"

/* derived name: pushes a block of kind 0 on the function state's stack of
 * blocks (tlg_game_compiler00da5b20.h): its int at +0x14 set to -1, its word
 * at +0xc the low word of the state's int at +0xc44, its int at +0x10
 * cleared */
void FUN_00daec00(Compiler00da5b20 *self) /* derived name */
{
    Block00daec00 *block = pushBlock(self->funcState);
    block->kind = 0;
    block->unknown14 = -1;
    block->unknownc = self->funcState->unknownc44;
    block->unknown10 = 0;
}
