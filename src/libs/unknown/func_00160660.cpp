/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpBodyManager::FUN_00160660(u32 bodyId) /* derived name */
{
    hknpBody &body = bodies[bodyId];
    body.flags &= ~0xf;
    if (body.shape && D_16dc5f8) {
        body.shape->removeReference();
    }
    body.id = 0x7fffffff;
    body.motionId = 0x7fffffff;

    const PointerMap::Iterator it = recordIndices48.FUN_00013ad0(hkUlong(bodyId));
    if (recordIndices48.isValid(it)) {
        const int index = int(recordIndices48.getValue(it));
        const int nextFree = firstFreeRecord68;
        Record48 &record = records58[index];
        record.vector0 = _mm_blend_ps(record.vector0, D_14b2060[1], 8);
        record.nextFree = nextFree;
        firstFreeRecord68 = index;
        recordIndices48.FUN_00013c10(it);
    }

    body.nextFreeBodyId() = firstFreeBodyId;
    firstFreeBodyId = bodyId;
    numBodies98--;
}
