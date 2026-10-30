/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived name: the stage's name for the dumps: a code for the initial
 * stage, a stage of one of the three lists or an unknown one, then the list's
 * count of the stage's record and one or two of its indices, as many as the
 * code takes; the node's style an ellipse when the flags are set. */
void hknpSolverStageTask::getName(hkStringBuf *name, hkStringBuf *description) const
{
    const char *attributes = "shape=box";
    const char *code;
    int count = 0;
    int numIndices = 0;
    switch (info.type) {
    case 0:
        count = stages->lists[info.index1]->get(info.index2).count;
        switch (info.index1) {
        case 2:
            code = "FC";
            attributes = "fillcolor=\"#c0f0c0\"";
            numIndices = 1;
            break;
        case 1:
            code = "MC";
            attributes = "fillcolor=\"#e0ffe0\"";
            numIndices = 2;
            break;
        case 0:
            code = "JC";
            attributes = "fillcolor=\"#e0ff00\"";
            numIndices = 2;
            break;
        default:
            code = "?C";
            break;
        }
        break;
    case 1:
        code = "IN";
        numIndices = 1;
        break;
    default:
        code = "??";
        break;
    }
    if (numIndices == 2) {
        FUN_00011900(name, "Solve/%s %i\\n%d:%d", code, count, info.index3, info.index4);
    } else if (numIndices == 1) {
        FUN_00011900(name, "Solve/%s %i\\n%d", code, count, info.index3);
    } else {
        FUN_00011900(name, "Solve/%s", code);
    }
    if (description) {
        FUN_00011900(description, "%s%s", attributes, info.flags ? ",shape=ellipse" : "");
    }
}
