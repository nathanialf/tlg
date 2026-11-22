/* src/include/tlg_game_drawcontext.h: the render's draw context (its draw
 * functions' assertions name JsDeviceContext.cpp), as far as its draws read
 * it, with the graphics library context's inline setters it expands
 * (FUN_01314290, FUN_013198b0, FUN_01319a00). Every name here is derived. */
#ifndef TLG_GAME_DRAWCONTEXT_H
#define TLG_GAME_DRAWCONTEXT_H

#include "tlg_game_commandbuffer.h"
#include "tlg_game_gnm.h"

#define BASE_GFX_CONTEXT_HEADER /* derived name */                                                 \
    "..\\..\\..\\external\\ps4\\include_common\\gnmx/basegfxcontext.h"
#define DEVICE_CONTEXT_FILE /* derived name */                                                     \
    "D:\\trico\\engine\\anzu\\engine_src\\render\\ps4\\JsDeviceContext.cpp"

/* derived names: the second command buffer's holder at +0x4aa8, its
 * preparation before a draw (FUN_0132e330, not written) and the two-word
 * marker packet written into its buffer when there is room */
struct CommandBufferHolder0132e330 {
    CommandBuffer01496a80 *commands; /* +0x0 */

    void writeMarker()
    {
        CommandBuffer01496a80 *buffer = commands;
        if (buffer->remaining() < 2 && !buffer->reserve(buffer, 2, buffer->userData))
            return;
        u32 *packet = buffer->cursor;
        packet[0] = 0xc0008500;
        packet[1] = 0;
        buffer->cursor += 2;
    }
};

/* the graphics library's import (config/imports.base.txt), declared here
 * until tlg_sce_gnm.h takes it: writes a draw of indexCount indices from
 * indexOffset into `dwords` words of a command buffer; zero when written.
 * The parameter names are derived. */
extern "C" int sceGnmDrawIndexOffset(unsigned *commands, unsigned dwords, unsigned indexOffset,
                                     unsigned indexCount, unsigned flags);
/* likewise: a draw of indexCount generated indices into `dwords` words */
extern "C" int sceGnmDrawIndexAuto(unsigned *commands, unsigned dwords, unsigned indexCount,
                                   unsigned flags);

/* the vertex shader as Draw's check reads it (JsVertexShader.cpp): the
 * compute-and-vertex part's shader, which a plain draw must not have */
struct JsVertexShader {
    u8 unknown0[0x420];

    struct {
        void *m_pGnmShader; /* +0x420 */
    } m_gnmShaderCsVs;
};

struct DrawContext01314290; /* derived name */

void FUN_0132e330(CommandBufferHolder0132e330 *holder); /* derived name: the holder's preparation */

/* derived names: the state a draw needs written before it (false: the
 * draw is dropped; the arguments are not traced; not written) */
bool FUN_013143e0(DrawContext01314290 *self, u32 unknown, bool indexed);

struct DrawContext01314290 { /* derived name */
    u8 unknown0[0x30];
    u32 drawCount; /* +0x30 */
    u8 unknown34[4];
    u32 indexTotal; /* +0x38: the indices drawn, every instance counted */
    u8 unknown3c[0x23c];
    u32 unknown278; /* +0x278: 0x200 writes no index buffer */
    u8 unknown27c[0x41f4];
    u64 indexAddress; /* +0x4470 */
    u32 indexCount;   /* +0x4478 */
    u8 unknown447c[0x4698 - 0x447c];
    JsVertexShader *m_pCurrentVertexShader; /* +0x4698 */
    u8 unknown46a0[0x4724 - 0x46a0];
    u32 instanceCount; /* +0x4724 */
    u8 unknown4728[0x74];
    u32 unknown479c; /* +0x479c */
    u32 unknown47a0; /* +0x47a0 */
    u8 unknown47a4[0x1c];
    CommandBuffer01496a80 commands; /* +0x47c0 */
    u32 unknown47e8;                /* +0x47e8: bit 0 goes with each draw */
    u8 unknown47ec[0xf2];
    u8 dispatchDrawOpen : 1; /* +0x48de, bit 0 */
    u8 unknown48df[0x1c9];
    CommandBufferHolder0132e330 secondCommands; /* +0x4aa8 */
    u8 unknown4ab0[0xe555];
    u8 markerFlags;  /* +0x13005: bit 0, a marker packet is owed */
    u8 unknown13006; /* +0x13006 */

    void Draw(u32 VertexCount, u32 StartVertexLocation);
    void DrawIndexedCommon(u32 indexCount, u32 indexOffset, u32 value479c, bool indexed);
    void DrawIndexedInstanced(u32 indexCount, u32 instances, u32 indexOffset, u32 value479c);

    void setIndexBuffer(u64 indexAddr)
    {
        GNM_ASSERT_MSG(BASE_GFX_CONTEXT_HEADER, 246, !dispatchDrawOpen,
                       "setIndexBuffer can't be called between beginDispatchDraw and "
                       "endDispatchDraw");
        if (commands.remaining() < 3 && !commands.reserve(&commands, 3, commands.userData))
            return;
        u32 *packet = commands.cursor;
        packet[0] = 0xc0012600;
        packet[1] = static_cast<u32>(indexAddr) & 0xfffffffe;
        packet[2] = static_cast<u32>(indexAddr >> 32) & 0xff;
        commands.cursor += 3;
    }

    void setIndexCount(u32 count)
    {
        if (commands.remaining() < 2 && !commands.reserve(&commands, 2, commands.userData))
            return;
        u32 *packet = commands.cursor;
        packet[0] = 0xc0001300;
        packet[1] = count;
        commands.cursor += 2;
    }

    /* the draw itself, written by the library (sceGnmDrawIndexOffset) into
     * nine words; kept only when it succeeds */
    void drawIndexOffset(u32 indexOffset, u32 indexCount)
    {
        if (commands.remaining() < 9 && !commands.reserve(&commands, 9, commands.userData))
            return;
        if (sceGnmDrawIndexOffset(commands.cursor, 9, indexOffset, indexCount, unknown47e8 & 1) ==
            0)
            commands.cursor += 9;
    }

    /* the auto-index draw, written by the library (sceGnmDrawIndexAuto)
     * into seven words; kept only when it succeeds */
    void drawIndexAuto(u32 indexCount)
    {
        if (commands.remaining() < 7 && !commands.reserve(&commands, 7, commands.userData))
            return;
        if (sceGnmDrawIndexAuto(commands.cursor, 7, indexCount, unknown47e8 & 1) == 0)
            commands.cursor += 7;
    }
};

#endif
