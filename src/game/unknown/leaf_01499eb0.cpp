/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* The import (config/imports.base.txt): writes the six-dword packet that
 * closes a marker at the command pointer. */
extern "C" int sceGnmInsertPopMarker(u32 *commands, u32 dwords);

/* derived names: a command buffer at +0x47c0 of its owner (FUN_01496a80's, leaf_01496a80.cpp): the command pointer
 * at +0x10, the end at +0x8, and a callback at +0x18 (with its user data at
 * +0x20) asked for room when fewer dwords are left than a packet needs; a
 * false answer drops the packet. */
struct CommandBuffer01499eb0; /* derived name */

typedef bool (*Reserve01499eb0)(CommandBuffer01499eb0 *buffer, u32 dwords,
                                void *userData); /* derived name */

struct CommandBuffer01499eb0 /* derived name */
{
    u8 unknown0[8];
    u32 *end;                /* +0x8 */
    u32 *cursor;             /* +0x10 */
    Reserve01499eb0 reserve; /* +0x18 */
    void *userData;          /* +0x20 */

    u32 remaining() const
    {
        return static_cast<u32>(end - cursor);
    }
};

struct Object01499eb0 /* derived name */
{
    u8 unknown0[0x47c0];
    CommandBuffer01499eb0 commands; /* +0x47c0 */
};

/* derived names: closes a marker in the owner's command buffer; its pointer
 * is at 0x16c3ad8 (a vtable without a row). */
void FUN_01499eb0(Object01499eb0 *self) /* derived name */
{
    CommandBuffer01499eb0 &commands = self->commands;
    if (commands.remaining() < 6 && !commands.reserve(&commands, 6, commands.userData))
        return;
    sceGnmInsertPopMarker(commands.cursor, 6);
    commands.cursor += 6;
}
