/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_commandbuffer.h"
#include "tlg_types.h"

struct Object01303ce0 { /* derived name */
    u8 unknown0[0x60];
    CommandBuffer01496a80 commands; /* +0x60 */
};

/* derived name: writes a packet of seven words carrying a 64-bit value (its
 * low word, then its high word), when there is room for it */
void FUN_01303ce0(Object01303ce0 *self, u64 value) /* derived name */
{
    CommandBuffer01496a80 &commands = self->commands;
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
