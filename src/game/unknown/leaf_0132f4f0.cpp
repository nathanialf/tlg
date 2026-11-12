/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a graphics command buffer (the end of its space at +0x8,
 * the write position at +0x10, the function at +0x18 that makes room, given
 * the buffer, the dwords wanted and the word at +0x20); its packets are the
 * type-3 set-context-register packets (header 0xc0006900 with the count of
 * data dwords less one in bits 16 to 29, then the register's offset and its
 * values). FUN_0132f4f0 (called by FUN_0130c100, FUN_013143e0 and
 * FUN_01498620) clears the sixteen registers from 0x2fe and the two from
 * 0x2f5 under one reservation of 22 dwords, then the register 0x2f8 under
 * one of 3; a reservation that fails skips its packets. The first two
 * packets move the write position on from the field read again after their
 * stores (`mov rax, [rbx+0x10]` after the zeros, `add rax, 0x10` after the
 * vector store), the third from the pointer it wrote through. */
struct CommandBuffer0132f4f0 { /* derived name */

    bool reserve(u32 dwords) /* derived name */
    {
        if (static_cast<u32>(end - cmd) < dwords)
            return makeRoom(this, dwords, userData);
        return true;
    }

    u32 *begin; /* +0x0: not read here */
    u32 *end;   /* +0x8 */
    u32 *cmd;   /* +0x10 */
    bool (*makeRoom)(CommandBuffer0132f4f0 *buffer, u32 dwords, void *userData); /* +0x18 */
    void *userData;                                                              /* +0x20 */
};

void FUN_0132f4f0(CommandBuffer0132f4f0 *buffer) /* derived name */
{
    if (buffer->reserve(22)) {
        u32 *cmd = buffer->cmd;
        cmd[0] = 0xc0106900;
        cmd[1] = 0x2fe;
        for (int i = 0; i < 16; ++i)
            cmd[2 + i] = 0;
        buffer->cmd += 18;
        cmd = buffer->cmd;
        cmd[0] = 0xc0026900;
        cmd[1] = 0x2f5;
        cmd[2] = 0;
        cmd[3] = 0;
        buffer->cmd += 4;
    }
    if (buffer->reserve(3)) {
        u32 *cmd = buffer->cmd;
        cmd[0] = 0xc0016900;
        cmd[1] = 0x2f8;
        cmd[2] = 0;
        buffer->cmd = cmd + 3;
    }
}
