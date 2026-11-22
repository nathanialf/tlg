/* src/include/tlg_game_commandbuffer.h: the command buffer of 32-bit words
 * at +0x60 of the objects that write packets into it (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_COMMANDBUFFER_H
#define TLG_GAME_COMMANDBUFFER_H

#include "tlg_types.h"

/* derived names: the end at +0x8 and the write position at +0x10, and a
 * callback at +0x18 (with its data at +0x20) asked for room when fewer words
 * are left than a packet needs; a false answer drops the packet
 * (FUN_01496a80, FUN_01496a00, FUN_01303ce0) */
struct CommandBuffer01496a80; /* derived name */

/* whether the console runs in its Neo mode (leaf_012fcfd0.cpp) */
int FUN_012fcfd0(); /* derived name */

typedef bool (*Reserve01496a80)(CommandBuffer01496a80 *buffer, u32 dwords,
                                void *userData); /* derived name */

struct CommandBuffer01496a80 /* derived name */
{
    u8 unknown0[8];
    u32 *end;                /* +0x8 */
    u32 *cursor;             /* +0x10 */
    Reserve01496a80 reserve; /* +0x18 */
    void *userData;          /* +0x20 */

    u32 remaining() const
    {
        return static_cast<u32>(end - cursor);
    }

    /* derived name: two four-dword packets (the type-3 header 0xc0024600)
     * for the registers 0x138, a size by the console's mode, and 0x139, the
     * address of the counter at the index aligned to eight bytes and its
     * bits 32 to 39, when there is room for them (JsDeviceContext's slots
     * 29 and 30) */
    void writeCounterAddress(const u64 *counters, u32 index)
    {
        if (remaining() < 8 && !reserve(this, 8, userData))
            return;
        u32 size = FUN_012fcfd0() == 1 ? 0x7fffc00 : 0x7fc00;
        const u64 address = reinterpret_cast<u64>(&counters[index]);
        u32 low = static_cast<u32>(address & 0xfffffff8);
        u32 high = static_cast<u32>((address >> 32) & 0xff);
        u32 *packet = cursor;
        packet[0] = 0xc0024600;
        packet[1] = 0x138;
        packet[2] = size;
        packet[3] = 0;
        cursor += 4;
        packet = cursor;
        packet[0] = 0xc0024600;
        packet[1] = 0x139;
        packet[2] = low;
        packet[3] = high;
        cursor += 4;
    }

    /* derived name: the six-word packet 0xc0044700 for a register, with an
     * address aligned to eight bytes (its low word, then bits 32 to 39 of
     * it with bit 31 set) and two zero words, when there is room for it
     * (JsDeviceContext's slot 28) */
    void writeEvent(u32 reg, u64 address)
    {
        if (remaining() < 6 && !reserve(this, 6, userData))
            return;
        const u64 aligned = address & 0xfffffffff8ULL;
        const u32 low = u32(aligned);
        const u32 high = u32(aligned >> 32) | 0x80000000;
        u32 *packet = cursor;
        packet[0] = 0xc0044700;
        packet[1] = reg;
        packet[2] = low;
        packet[3] = high;
        packet[4] = 0;
        packet[5] = 0;
        cursor += 6;
    }

    /* derived name: the three-dword packet 0xc0016900 setting the register
     * 1, when there is room for it */
    void setRegister1(u32 value)
    {
        if (remaining() < 3 && !reserve(this, 3, userData))
            return;
        u32 *packet = cursor;
        packet[0] = 0xc0016900;
        packet[1] = 1;
        packet[2] = value;
        cursor = packet + 3;
    }
};

#endif
