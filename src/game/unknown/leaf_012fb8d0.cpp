/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"

#include "tlg_game_commandbuffer.h"
#include "tlg_game_gnm.h"

/* derived name: the packets that set a render target's fourteen registers
 * from 0x318 and the slot's fifteen (0xc00e6900), the fifteenth in a nop
 * packet after them (0xc0001000), or, for no target or one with no base
 * address, the slot's color info register 0x31c cleared (0xc0016900), when
 * there is room for them */
void FUN_012fb8d0(CommandBuffer01496a80 *buffer, u32 slot, const RenderTarget0149a070 *target)
{
    u32 dwords = target && FUN_012fc0a0(target) ? 18 : 3;
    if (buffer->remaining() < dwords && !buffer->reserve(buffer, dwords, buffer->userData))
        return;
    if (target && FUN_012fc0a0(target)) {
        const u32 reg = 0x318 + slot * 15;
        u32 *packet = buffer->cursor;
        packet[0] = 0xc00e6900;
        packet[1] = reg;
        memcpy(&packet[2], target, 14 * sizeof(u32));
        packet = buffer->cursor + 16;
        packet[0] = 0xc0001000;
        packet[1] = target->word3c;
        buffer->cursor = packet + 2;
        return;
    }
    const u32 reg = 0x31c + slot * 15;
    u32 *packet = buffer->cursor;
    packet[0] = 0xc0016900;
    packet[1] = reg;
    packet[2] = 0;
    buffer->cursor = packet + 3;
}
