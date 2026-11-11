/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A free record: its first vector's w the table's -1, the next free one's
 * index after the vectors. derived name. */
static inline void setEmptyRecord(hknpBodyManager::Record48 &record, int next)
{
    record.vector0 = _mm_blend_ps(record.vector0, D_14b2060[1], 8);
    record.nextFree = next;
}

/* A new body set up from its construction info (0x160930): the body's own
 * fields from the info, its quality the default of its kind when the info
 * leaves it invalid (3 for a body with a motion, 0 for a static one, whose
 * motion is the static motion 0), then its name, mass, motion properties
 * and mass distribution recorded by its id, a record taken from the free
 * list (grown by eight, or doubled) when the body has none. */
// NONMATCHING: the inline-cost margin: the base inlines the mass and the motion properties' sets
// (0x160e40, 0x160f30, out of line in this tree and in the base's object beside it), which 3.3 prices
// over 225 here and under 325 with the keyword's hint; with both inlined (hknpBodyManager.cpp's
// order, a diagnostic) 205 of 246 at the base's frame, the residual SimplifyCFG's hoist of the new
// records' address into the linking loop's header (HoistThenElseCodeToIf: the base hoists the index
// and the data load, not the address; NOTES round 132C).
void hknpBodyManager::FUN_00160930(hknpBody *body, u32 bodyId, const hknpBodyCinfo &cinfo, int kind)
{
    body->FUN_0003aa60(bodyId, cinfo);
    const u8 qualityId = cinfo.qualityId;
    if (kind) {
        body->qualityId = qualityId != 0xff ? qualityId : 3;
        body->flags |= 2;
    } else {
        body->qualityId = qualityId != 0xff ? qualityId : 0;
        body->motionId = 0;
        body->flags |= hknpBody::IS_STATIC;
    }
    FUN_00160cd0(bodyId, cinfo.name.cString());
    FUN_00160e40(bodyId, cinfo.mass);
    FUN_00160f30(bodyId, cinfo.motionPropertiesId);
    if (const hknpRefMassDistribution *massDistribution = cinfo.massDistribution) {
        const hknpMassDistribution &distribution = massDistribution->massDistribution;
        PointerMap &map = recordIndices48;
        const PointerMap::Iterator it = map.FUN_00013ad0(hkUlong(bodyId));
        hkArray<Record48> &records = records58;
        if (map.isValid(it)) {
            const int index = int(map.getValue(it));
            *reinterpret_cast<hknpMassDistribution *>(&records[index]) = distribution;
        } else {
            if (firstFreeRecord68 < 0) {
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
                        setEmptyRecord(records[i], i + 1);
                    }
                    setEmptyRecord(records[i], firstFreeRecord68);
                }
                firstFreeRecord68 = oldCapacity;
            }
            const int index = firstFreeRecord68;
            firstFreeRecord68 = records[index].nextFree;
            new (&records[index]) hknpMassDistribution(distribution);
            map.FUN_000138a0(hkContainerHeapAllocator::get(), hkUlong(bodyId), hkUlong(u32(index)));
        }
    }
}
