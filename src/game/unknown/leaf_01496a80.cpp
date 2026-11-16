/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_commandbuffer.h"
#include "tlg_types.h"

/* The import (config/imports.base.txt): writes the six-dword packet that
 * closes a marker at the command pointer. */
extern "C" int sceGnmInsertPopMarker(u32 *commands, u32 dwords);

struct Object01496a80 /* derived name */
{
    u8 unknown0[0x60];
    CommandBuffer01496a80 commands; /* +0x60 */
};

/* derived names: closes a marker in the owner's command buffer. */
void FUN_01496a80(Object01496a80 *self) /* derived name */
{
    CommandBuffer01496a80 &commands = self->commands;
    if (commands.remaining() < 6 && !commands.reserve(&commands, 6, commands.userData))
        return;
    sceGnmInsertPopMarker(commands.cursor, 6);
    commands.cursor += 6;
}
