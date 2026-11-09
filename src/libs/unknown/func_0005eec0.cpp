/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The command of a body's mass distribution set (derived names): primary
 * type 2, secondary type 20, 64 bytes padded; the distribution after the
 * body's id, built new (every byte 0xff) and then assigned. */
struct SetBodyMassDistributionCommand : public hkCommand /* derived name */
{
    SetBodyMassDistributionCommand(u32 id, const hknpMassDistribution &distribution)
        : hkCommand(64, 2, 20), bodyId(id)
    {
        massDistribution = distribution;
    }

    u32 bodyId;
    hknpMassDistribution massDistribution;
};

// NONMATCHING: the free list's growth and the record copies, 217 instructions as the base, 899
// bytes against 883: the base's linking loop is rotated under both guards with the last record
// at the loop's exit value, where this peels the first record's blend ahead of the inner guard
// (the select form of hkFreeListArray::grow gives the guards unrotated, the plain loop rotated
// without the outer guard); the new record's copy is two vectors and two quadwords in the base
// (stores reversed), three vectors here; the frame is 0x10 smaller.
void hknpWorld::FUN_0005eec0(u32 bodyId, const hknpMassDistribution &massDistribution, int mode)
{
    SetBodyMassDistributionCommand command(bodyId, massDistribution);
    const hknpBody &body = bodyManager.bodies[bodyId];

    PointerMap &recordIndices = bodyManager.recordIndices48;
    const PointerMap::Iterator it = recordIndices.FUN_00013ad0(hkUlong(bodyId));
    if (recordIndices.isValid(it)) {
        const int index = int(recordIndices.getValue(it));
        *reinterpret_cast<hknpMassDistribution *>(&bodyManager.records58[index]) = massDistribution;
    } else {
        hkArray<hknpBodyManager::Record48> &records = bodyManager.records58;
        if (bodyManager.firstFreeRecord68 < 0) {
            const int oldCapacity = records.getSize();
            const int newCapacity =
                hkMath::max2(oldCapacity + 8, oldCapacity ? 2 * oldCapacity : 1);
            const int numNew = newCapacity - oldCapacity;
            records.reserveExactly(newCapacity);
            records.expandByUnchecked(numNew);
            const int last = newCapacity - 1;
            if (oldCapacity <= last) {
                int i = oldCapacity;
                for (; i < last; i++) {
                    hknpBodyManager::Record48 &record = records[i];
                    record.vector0 = _mm_blend_ps(record.vector0, D_14b2060[1], 8);
                    record.nextFree = i + 1;
                }
                hknpBodyManager::Record48 &record = records[i];
                record.vector0 = _mm_blend_ps(record.vector0, D_14b2060[1], 8);
                record.nextFree = bodyManager.firstFreeRecord68;
            }
            bodyManager.firstFreeRecord68 = oldCapacity;
        }
        const int index = bodyManager.firstFreeRecord68;
        bodyManager.firstFreeRecord68 = records[index].nextFree;
        *reinterpret_cast<hknpMassDistribution *>(&records[index]) = massDistribution;
        recordIndices.FUN_000138a0(hkContainerHeapAllocator::get(), hkUlong(bodyId),
                                   hkUlong(u32(index)));
    }

    if (!(body.flags & 1) && mode != 2) {
        if (!(body.flags & 9)) {
            FUN_0004e0c0(bodyId);
        }
        FUN_0004bcd0(body.motionId);
    }
    signals.bodyChangedSignal.fire(this, bodyId);
}
