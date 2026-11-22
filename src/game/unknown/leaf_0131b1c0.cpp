/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_game_jsdevicecontext.h"
#include "tlg_game_object05adaaa8.h"

/* JsVolatileMemory::AllocateInArc (leaf_01305ce0.cpp, a draft): called by
 * its address until it has a row */
u64 FUN_01305ce0(JsVolatileMemory *memory, u32 size, u32 alignment);

/* derived name: eight bytes of the device's volatile memory (64-byte
 * aligned) set to 0x11, then, when there is room, the six-dword end-of-pipe
 * event (the type-3 header 0xc0044700) that writes 0x10 to them, the
 * label's address masked to 40 bits and 8 bytes; the label returned. */
u64 *JsDeviceContext::writeEndOfPipeLabel()
{
    u64 *label = reinterpret_cast<u64 *>(FUN_01305ce0(D_5adaaa8->volatileMemory, 8, 0x40));
    *label = 0x11;
    CommandBuffer01496a80 &commands = this->commands;
    if (commands.remaining() < 6 && !commands.reserve(&commands, 6, commands.userData))
        return label;
    u64 address = reinterpret_cast<u64>(label) & 0xfffffffff8;
    u32 *packet = commands.cursor;
    packet[0] = 0xc0044700;
    packet[1] = 0x38504;
    packet[2] = static_cast<u32>(address);
    packet[3] = static_cast<u32>(address >> 32) | 0x40000000;
    packet[4] = 0x10;
    packet[5] = 0;
    commands.cursor += 6;
    return label;
}
