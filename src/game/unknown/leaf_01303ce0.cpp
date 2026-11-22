/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_jscomputecontext.h"

/* derived name: writes a packet of seven words carrying a 64-bit value (its
 * low word, then its high word), when there is room for it */
void JsComputeContext::slot28(u64 value)
{
    CommandBuffer01496a80 &commands = this->commands;
    if (commands.remaining() < 7 && !commands.reserve(&commands, 7, commands.userData))
        return;
    const u32 high = u32(value >> 32);
    u32 *packet = commands.cursor;
    packet[0] = 0xc0054902;
    packet[1] = 0x62f;
    packet[2] = 0x83000000;
    packet[3] = u32(value);
    packet[4] = high;
    packet[5] = 0;
    packet[6] = 0;
    commands.cursor += 7;
}
