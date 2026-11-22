/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_jscomputecontext.h"

/* derived name: writes the three-word packet 0xc0017602 that sets the
 * register 0x215 to its three fields: the first argument in bits 0 to 9, the
 * second in bits 12 to 15 and the third in bits 16 to 21, when there is room
 * for it; the same body as JsDeviceContext's slot 23 (leaf_0131b330.cpp) */
void JsComputeContext::setRegister215(u32 low, u32 middle, u32 high)
{
    CommandBuffer01496a80 &commands = this->commands;
    if (commands.remaining() < 3 && !commands.reserve(&commands, 3, commands.userData))
        return;
    u32 *packet = commands.cursor;
    packet[0] = 0xc0017602;
    packet[1] = 0x215;
    packet[2] = (low & 0x3ff) | (middle & 0xf) << 12 | (high & 0x3f) << 16;
    commands.cursor = packet + 3;
}
