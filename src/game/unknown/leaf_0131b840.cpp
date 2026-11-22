/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_jsdevicecontext.h"

/* derived name: writes a three-dword packet (the type-3 header 0xc0012000,
 * two zero dwords) at the command pointer, bit 0 of the byte at +0x47e8
 * cleared once there is room. */
void JsDeviceContext::slot32()
{
    CommandBuffer01496a80 &commands = this->commands;
    if (commands.remaining() < 3 && !commands.reserve(&commands, 3, commands.userData))
        return;
    unknown47e8 &= ~1;
    u32 *packet = commands.cursor;
    packet[0] = 0xc0012000;
    packet[1] = 0;
    packet[2] = 0;
    commands.cursor += 3;
}
