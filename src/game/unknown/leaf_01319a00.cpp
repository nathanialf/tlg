/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_drawcontext.h"

/* DrawIndexedInstanced (the name from its assertion message): an indexed
 * draw of several instances, as DrawIndexedCommon (FUN_013198b0) draws one: the instance count
 * kept, the draw's state written, the draw packet, the owed marker, and the
 * counts with every instance's indices. */
void DrawContext01314290::DrawIndexedInstanced(u32 indexCount, u32 instances, u32 indexOffset,
                                               u32 value479c)
{
    if (instanceCount != instances)
        instanceCount = instances;
    unknown479c = value479c;
    unknown47a0 = 0;
    if (!FUN_013143e0(this, 0, true))
        return;
    GNM_ASSERT_MSG(DEVICE_CONTEXT_FILE, 3379, !dispatchDrawOpen,
                   "drawIndexOffset can't be called between beginDispatchDraw and "
                   "endDispatchDraw");
    FUN_0132e330(&secondCommands);
    drawIndexOffset(indexOffset, indexCount);
    if (markerFlags & 1) {
        secondCommands.writeMarker();
        markerFlags = 0;
        unknown13006 = 1;
    }
    ++drawCount;
    indexTotal += indexCount * instances;
}
