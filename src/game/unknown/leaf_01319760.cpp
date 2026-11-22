/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_jsbuffer.h"
#include "tlg_game_jsdevicecontext.h"

/* derived names: the count of the view's slot written to the buffer's base
 * address: directly when the view was bound with an initial count (not
 * ~0), else, when there is room, by the seven-dword copy packet (the type-3
 * header 0xc0055000) from the counts' word at the slot; the context's stamp
 * at +0x47ac then stored into the buffer either way. */
void JsDeviceContext::CopyStructureCount(JsBuffer *pDstBuffer, u32 DstAlignedByteOffset,
                                         JsUnorderedAccessView *pSrcView)
{
    u32 slot = pSrcView->counterSlot;
    u64 address =
        (static_cast<u64>(pDstBuffer->descriptor[1]) & 0xfff) << 32 | pDstBuffer->descriptor[0];
    u32 count = m_initialCounts[slot];
    if (count != ~0u) {
        *reinterpret_cast<u32 *>(address) = count;
    } else {
        CommandBuffer01496a80 &commands = this->commands;
        u32 base = counterBase;
        if (commands.remaining() >= 7 || commands.reserve(&commands, 7, commands.userData)) {
            u64 source = base + slot * sizeof(u32);
            u32 *packet = commands.cursor;
            packet[0] = 0xc0055000;
            packet[1] = 0xa4004000;
            packet[2] = static_cast<u32>(source);
            packet[3] = static_cast<u32>(source >> 32);
            packet[4] = static_cast<u32>(address);
            packet[5] = static_cast<u32>(address >> 32);
            packet[6] = 4;
            commands.cursor += 7;
        }
    }
    pDstBuffer->unknown2c = unknown47ac;
}
