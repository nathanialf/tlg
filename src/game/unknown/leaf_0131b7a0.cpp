/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_commandbuffer.h"
#include "tlg_types.h"

struct Object0131b7a0 { /* derived name */
    u8 unknown0[0x47c0];
    CommandBuffer01496a80 commands; /* +0x47c0 */
    u8 unknown47e8;                 /* +0x47e8: bit 0 set here */
};

/* derived name: writes the three-word packet 0xc0012000 carrying an address
 * aligned to 16 bytes (its low word, then bits 32 to 39 of it beside the low
 * byte of the second argument at bits 8 to 15 and bit 16), bit 0 of the byte
 * at +0x47e8 set once there is room; FUN_0131b840 writes the packet that
 * clears it */
// NONMATCHING: register assignment and order only (round 399C, two-stage): the
// base copies the low word to edx before it widens the index byte into ecx
// and ors the high byte into it (`or ecx, esi`); the build widens the index
// into esi and ors it into the high byte (`or edx, esi`). Same with the index
// a masked u32 and with the high byte masked as 64 bits. Round 448E: the words
// computed before the cursor is read move the difference to the index's
// register (32/41).
void FUN_0131b7a0(Object0131b7a0 *self, u8 index, u64 address) /* derived name */
{
    CommandBuffer01496a80 &commands = self->commands;
    if (commands.remaining() < 3 && !commands.reserve(&commands, 3, commands.userData))
        return;
    self->unknown47e8 |= 1;
    u32 *packet = commands.cursor;
    packet[0] = 0xc0012000;
    packet[1] = u32(address) & ~0xfu;
    packet[2] = u32(index) << 8 | u8(address >> 32) | 0x10000;
    commands.cursor += 3;
}
