/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_drawcontext.h"

/* DrawIndexedCommon (the name from its assertion message): an indexed draw
 * of one instance: the instance count kept at 1, the draw's state written
 * (FUN_013143e0), then the draw packet, the owed marker, and the counts. */
void DrawContext01314290::DrawIndexedCommon(u32 indexCount, u32 indexOffset, u32 value479c,
                                            bool indexed)
{
    if (instanceCount != 1)
        instanceCount = 1;
    unknown479c = value479c;
    unknown47a0 = 0;
    if (!FUN_013143e0(this, 0, indexed))
        return;
    GNM_ASSERT_MSG(DEVICE_CONTEXT_FILE, 3291, !dispatchDrawOpen,
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
    indexTotal += indexCount;
}
