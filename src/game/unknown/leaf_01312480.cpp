/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_assert.h"
#include "tlg_game_drawcontext.h"

struct IndexBuffer01314290;
void FUN_01314290(DrawContext01314290 *self, const IndexBuffer01314290 *buffer); /* derived name */

/* Draw (the name from its reports): a draw of one instance without an index
 * buffer: the bound vertex shader checked to have no compute-and-vertex
 * part, the index buffer unbound, the draw's state written (FUN_013143e0),
 * then the auto-index draw packet, the owed marker, and the counts. */
void DrawContext01314290::Draw(u32 VertexCount, u32 StartVertexLocation)
{
    ANZU_ASSERT(DEVICE_CONTEXT_FILE, 3248,
                m_pCurrentVertexShader->m_gnmShaderCsVs.m_pGnmShader == nullptr);
    if (instanceCount != 1)
        instanceCount = 1;
    FUN_01314290(this, nullptr);
    unknown479c = StartVertexLocation;
    unknown47a0 = 0;
    if (!FUN_013143e0(this, 0, true))
        return;
    GNM_ASSERT_MSG(DEVICE_CONTEXT_FILE, 3258, !dispatchDrawOpen,
                   "drawIndexAuto can't be called between beginDispatchDraw and endDispatchDraw");
    FUN_0132e330(&secondCommands);
    drawIndexAuto(VertexCount);
    if (markerFlags & 1) {
        secondCommands.writeMarker();
        markerFlags = 0;
        unknown13006 = 1;
    }
    ++drawCount;
    indexTotal += VertexCount;
}
