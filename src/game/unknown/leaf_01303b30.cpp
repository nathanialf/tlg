/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_commandbuffer.h"
#include "tlg_types.h"

struct Object01303b30 { /* derived name */
    u8 unknown0[0x60];
    CommandBuffer01496a80 commands; /* +0x60 */
};

/* derived name: writes the seven-word packet 0xc0053c00 that waits for the
 * word at an address to equal 0x10: an address above 0xffff is memory (bit 4
 * of the second word, the address aligned to four bytes), else a register
 * number (its low 16 bits); when there is room for it; the same body as
 * FUN_0131b280 with its buffer at +0x47c0 */
// NONMATCHING: instruction order only (round 399C, two-stage): the build copies
// the address's low word (`mov edi, r14d`) before the header store, the base
// after the select of the mask (`cmova; mov edx, r14d`); the registers follow.
// Same with the mask as a 64-bit and truncated and with the address a pointer.
void FUN_01303b30(Object01303b30 *self, u64 address) /* derived name */
{
    CommandBuffer01496a80 &commands = self->commands;
    if (commands.remaining() < 7 && !commands.reserve(&commands, 7, commands.userData))
        return;
    const bool memory = address > 0xffff;
    const u32 mask = memory ? 0xfffffffc : 0xffff;
    u32 *packet = commands.cursor;
    packet[0] = 0xc0053c00;
    packet[1] = u32(memory) << 4 | 3;
    packet[2] = u32(address) & mask;
    packet[3] = u16(address >> 32);
    packet[4] = 0x10;
    packet[5] = 0xffffffff;
    packet[6] = 0xa;
    commands.cursor += 7;
}
