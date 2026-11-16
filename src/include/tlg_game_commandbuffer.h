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
};

#endif
