/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a command buffer at +0x47c0 of its owner, as
 * leaf_01499eb0.cpp names it (the command pointer at +0x10, the end at +0x8,
 * and a callback at +0x18 with its user data at +0x20 asked for room when
 * fewer dwords are left than a packet needs; a false answer drops the
 * packet). */
struct CommandBuffer0131b840; /* derived name */

typedef bool (*Reserve0131b840)(CommandBuffer0131b840 *buffer, u32 dwords,
                                void *userData); /* derived name */

struct CommandBuffer0131b840 /* derived name */
{
    u8 unknown0[8];
    u32 *end;                /* +0x8 */
    u32 *cursor;             /* +0x10 */
    Reserve0131b840 reserve; /* +0x18 */
    void *userData;          /* +0x20 */

    u32 remaining() const
    {
        return static_cast<u32>(end - cursor);
    }
};

struct Object0131b840 /* derived name */
{
    u8 unknown0[0x47c0];
    CommandBuffer0131b840 commands; /* +0x47c0 */
    u8 unknown47e8;                 /* +0x47e8: bit 0 cleared here */
};

/* derived names: slot 32 of the vtable whose slot 34 is FUN_01499eb0 (its
 * pointer at 0x16c3ac8; a vtable without a row): writes a three-dword packet
 * (the type-3 header 0xc0012000, two zero dwords) at the owner's command
 * pointer, bit 0 of the byte at +0x47e8 cleared once there is room. */
void FUN_0131b840(Object0131b840 *self) /* derived name */
{
    CommandBuffer0131b840 &commands = self->commands;
    if (commands.remaining() < 3 && !commands.reserve(&commands, 3, commands.userData))
        return;
    self->unknown47e8 &= ~1;
    u32 *packet = commands.cursor;
    packet[0] = 0xc0012000;
    packet[1] = 0;
    packet[2] = 0;
    commands.cursor += 3;
}
