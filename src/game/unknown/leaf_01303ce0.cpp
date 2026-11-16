/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a command buffer of 32-bit words: its end and the write
 * position, and the callback that makes room (called with the buffer, the
 * words wanted and its data; false when there is none) */
struct CommandBuffer01303ce0 {                                             /* derived name */
    u32 *begin;                                                            /* +0x0: not traced */
    u32 *end;                                                              /* +0x8 */
    u32 *position;                                                         /* +0x10 */
    bool (*reserve)(CommandBuffer01303ce0 *buffer, u32 words, void *data); /* +0x18 */
    void *data;                                                            /* +0x20 */
};

struct Object01303ce0 { /* derived name */
    u8 unknown0[0x60];
    CommandBuffer01303ce0 commands; /* +0x60 */
};

/* derived name: writes a packet of seven words carrying a 64-bit value (its
 * low word, then its high word), when there is room for it */
void FUN_01303ce0(Object01303ce0 *self, u64 value) /* derived name */
{
    CommandBuffer01303ce0 &commands = self->commands;
    if (u32(commands.end - commands.position) < 7 && !commands.reserve(&commands, 7, commands.data))
        return;
    const u32 high = u32(value >> 32);
    u32 *packet = commands.position;
    packet[0] = 0xc0054902;
    packet[1] = 0x62f;
    packet[2] = 0x83000000;
    packet[3] = u32(value);
    packet[4] = high;
    packet[5] = 0;
    packet[6] = 0;
    commands.position += 7;
}
