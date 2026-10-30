/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived name: the stage's name for the dumps: the initial stage, a
 * stage of a list (its code by the list, the list's count of the stage's
 * record, then its indices) or an unknown one, with a node style, an
 * ellipse when its flags are set. */
// NONMATCHING: 4 of 87, 337 bytes for 309: the base tail-merges the name's
// calls by format (IN with FC, JC with MC, ?C with ??), each case setting the
// code in rdx and the style in r15 before the shared call, so the style lives
// across the call in a callee-saved register; here each style is materialized
// after its call and the tails differ (docs/NOTES.md, Round 65A).
void hknpSolverStageTask::getName(hkStringBuf *name, hkStringBuf *description) const
{
    const char *attributes;
    if (info.type == 1) {
        attributes = "shape=box";
        FUN_00011900(name, "Solve/%s %i\\n%d", "IN", 0, info.index3);
    } else if (info.type == 0) {
        const int count = stages->lists[info.index1]->get(info.index2).count;
        switch (info.index1) {
        case 0:
            attributes = "fillcolor=\"#e0ff00\"";
            FUN_00011900(name, "Solve/%s %i\\n%d:%d", "JC", count, info.index3, info.index4);
            break;
        case 1:
            attributes = "fillcolor=\"#e0ffe0\"";
            FUN_00011900(name, "Solve/%s %i\\n%d:%d", "MC", count, info.index3, info.index4);
            break;
        case 2:
            attributes = "fillcolor=\"#c0f0c0\"";
            FUN_00011900(name, "Solve/%s %i\\n%d", "FC", count, info.index3);
            break;
        default:
            attributes = "shape=box";
            FUN_00011900(name, "Solve/%s", "?C");
            break;
        }
    } else {
        attributes = "shape=box";
        FUN_00011900(name, "Solve/%s", "??");
    }
    if (description) {
        FUN_00011900(description, "%s%s", attributes, info.flags ? ",shape=ellipse" : "");
    }
}
