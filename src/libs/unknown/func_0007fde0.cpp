/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkpLinearParametricCurve::FUN_0007fde0(hkArray<Vec4> &pointsOut) const /* derived name */
{
    const int capacity = pointsOut.getCapacity();
    if (capacity < points.getSize()) {
        if ((pointsOut.capacityAndFlags & hkArray<Vec4>::DONT_DEALLOCATE_FLAG) == 0) {
            hkContainerHeapAllocator::get().freeBytes(pointsOut.data, capacity * int(sizeof(Vec4)));
        }
        int numBytes = points.getSize() * int(sizeof(Vec4));
        Vec4 *storage = static_cast<Vec4 *>(hkContainerHeapAllocator::get().FUN_00008d70(numBytes));
        const int newCapacity = numBytes / int(sizeof(Vec4));
        pointsOut.data = storage;
        pointsOut.capacityAndFlags = newCapacity;
    }
    const int numPoints = points.getSize();
    pointsOut.size = numPoints;
    hkArrayUtil::copy(pointsOut.data, points.data, numPoints);
}
