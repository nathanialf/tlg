/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: every instruction but the registers of `this` and `mode`
// (r12 and r15 traded; the size differs by the loop's alignment). Greedy
// takes `mode` ([16r,880r], 864 slots) before the signal walk's slot pointer
// (848 slots in eight segments), so `mode` gets r15 and the walk's eviction
// of `this` from rbx sends it to r12; the base behaves as if the walk's
// pointer were queued first (docs/NOTES.md, Round 67A).

void hknpWorld::FUN_0005f240(u32 bodyId, int mode)
{
    PointerMap &recordIndices = bodyManager.recordIndices48;
    const PointerMap::Iterator it = recordIndices.FUN_00013ad0(hkUlong(bodyId));
    if (recordIndices.isValid(it)) {
        const int index = int(recordIndices.getValue(it));
        const int nextFree = bodyManager.firstFreeRecord68;
        hknpBodyManager::Record48 &record = bodyManager.records58[index];
        record.vector0 = _mm_blend_ps(record.vector0, D_14b2060[1], 8);
        record.nextFree = nextFree;
        bodyManager.firstFreeRecord68 = index;
        recordIndices.FUN_00013c10(it);
    }

    const hknpBody &body = bodyManager.bodies[bodyId];
    if (!(body.flags & 1) && mode != 2) {
        if (!(body.flags & 9)) {
            FUN_0004e0c0(bodyId);
        }
        FUN_0004bcd0(body.motionId);
    }
    signals.bodyChangedSignal.fire(this, bodyId);
}
