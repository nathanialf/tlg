/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_commandbuffer.h"
#include "tlg_types.h"

struct Object0131b3d0 { /* derived name */
    u8 unknown0[0x278];
    u32 mode; /* +0x278: 0x8000 picks the register 0x528 */
    u8 unknown27c[0x4544];
    CommandBuffer01496a80 commands; /* +0x47c0 */
};

/* derived name: the six-word packet 0xc0044700 for a register, with an
 * address aligned to eight bytes (its low word, then bits 32 to 39 of it
 * with bit 31 set) and two zero words, when there is room for it */
static inline void writeEvent(CommandBuffer01496a80 &commands, u32 reg,
                              u64 address) /* derived name */
{
    if (commands.remaining() < 6 && !commands.reserve(&commands, 6, commands.userData))
        return;
    const u64 aligned = address & 0xfffffffff8ULL;
    u32 *packet = commands.cursor;
    packet[0] = 0xc0044700;
    packet[1] = reg;
    packet[2] = u32(aligned);
    packet[3] = u32(aligned >> 32) | 0x80000000;
    packet[4] = 0;
    packet[5] = 0;
    commands.cursor += 6;
}

/* derived name: that packet for the register 0x528 when the mode at +0x278
 * is 0x8000, else for 0x514 */
// NONMATCHING: tail merge (round 399C, two-stage): the base keeps each arm's
// mask, shift and or before the shared stores (the stores alone merged); the
// build schedules the shift and or after the low word's store and merges them
// into the tail, 12/55.
void FUN_0131b3d0(Object0131b3d0 *self, u64 address) /* derived name */
{
    if (self->mode == 0x8000)
        writeEvent(self->commands, 0x528, address);
    else
        writeEvent(self->commands, 0x514, address);
}
