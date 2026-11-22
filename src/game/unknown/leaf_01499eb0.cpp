/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_jsdevicecontext.h"

/* The import (config/imports.base.txt): writes the six-dword packet that
 * closes a marker at the command pointer. */
extern "C" int sceGnmInsertPopMarker(u32 *commands, u32 dwords);

/* derived name: closes a marker in the command buffer. */
void JsDeviceContext::PopMarker()
{
    CommandBuffer01496a80 &commands = this->commands;
    if (commands.remaining() < 6 && !commands.reserve(&commands, 6, commands.userData))
        return;
    sceGnmInsertPopMarker(commands.cursor, 6);
    commands.cursor += 6;
}
