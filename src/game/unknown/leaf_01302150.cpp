/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_sce_gnm.h"
#include "tlg_types.h"

#include "tlg_game_jscomputecontext.h"

/* derived names: FUN_01300e30 first; then, when the byte at +0x1c7c is set,
 * FUN_0132f9a0 for the member at +0xa0 and the byte at +0x1a18 shifted to
 * bit 3 of the modifier; then a dispatch of the three counts of thread
 * groups written into the command buffer when there is room for its nine
 * words, bit 0 of the word at +0x88 in the modifier's bit 0; then the count
 * of dispatches at +0x34 raised and the groups' product added to the total
 * at +0x3c. */
void FUN_01300e30(JsComputeContext *self); /* derived name */
void FUN_0132f9a0(Member01302150 *member); /* derived name */

void JsComputeContext::Dispatch(u32 groupsX, u32 groupsY, u32 groupsZ)
{
    FUN_01300e30(this);
    u32 modifier = 0;
    if (unknown1c7c) {
        FUN_0132f9a0(&memberA0);
        modifier = unknown1a18 << 3;
    }
    CommandBuffer01496a80 &commands = this->commands;
    if (commands.remaining() >= 9 || commands.reserve(&commands, 9, commands.userData)) {
        if (sceGnmDispatchDirect(commands.cursor, 9, groupsX, groupsY, groupsZ,
                                 (unknown88 & 1) | modifier) == 0)
            commands.cursor += 9;
    }
    ++dispatches;
    groups += groupsX * groupsY * groupsZ;
}
