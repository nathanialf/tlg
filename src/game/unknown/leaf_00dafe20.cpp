/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_compiler00da5b20.h"

/* derived name: pushes a block of kind 3 on the function state's stack of
 * blocks (tlg_game_compiler00da5b20.h): its int at +0x14 and the top
 * block's int at +0x4 set to -1 */
void FUN_00dafe20(Compiler00da5b20 *self) /* derived name */
{
    Block00daec00 *block = pushBlock(self->funcState);
    block->kind = 3;
    block->unknown14 = -1;
    self->funcState->blockTop->unknown4 = -1;
}
