/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

int hknpWorld::FUN_0004ce80(const hknpMotionCinfo &cinfo)
{
    if (motionManager.firstFreeMotionId == 0x7fffffff) {
        signals.motionBufferFullSignal.fire(this, &motionManager);
    }
    const int motionId = motionManager.FUN_000475c0();
    motionManager.motions[motionId].FUN_001571c0(cinfo, spaceSplitter);
    if (object4f8->motionRecords.getSize() < motionId + 1) {
        object4f8->motionRecords.setSize(hkContainerHeapAllocator::get(), motionId + 1);
    }
    object4f8->motionRecords[motionId].FUN_00066860(motionId, cinfo.enableDeactivation);
    signals.motionCreatedSignal.fire(this, cinfo, motionId);
    return motionId;
}
