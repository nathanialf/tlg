/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkpParametricCurve *hkpLinearParametricCurve::FUN_0007ff00() const
{
    hkpLinearParametricCurve *curve = new hkpLinearParametricCurve();
    const int numPoints = points.getSize();
    for (int i = 0; i < numPoints; i++) {
        curve->addPoint(points[i]);
    }
    curve->closedLoop = closedLoop;
    curve->dirNotParallelToTangentAlongWholePath = setXYZ_0(dirNotParallelToTangentAlongWholePath);

    /* The distances copied over, the copy's storage replaced from the
     * containers' allocator when it is too small. */
    hkArray<float> &distanceOut = curve->distance;
    const int capacity = distanceOut.getCapacity();
    if (capacity < distance.getSize()) {
        if ((distanceOut.capacityAndFlags & hkArray<float>::DONT_DEALLOCATE_FLAG) == 0) {
            hkContainerHeapAllocator::get().freeBytes(distanceOut.data,
                                                      capacity * int(sizeof(float)));
        }
        int numBytes = distance.getSize() * int(sizeof(float));
        float *storage =
            static_cast<float *>(hkContainerHeapAllocator::get().FUN_00008d70(numBytes));
        const int newCapacity = numBytes / int(sizeof(float));
        distanceOut.data = storage;
        distanceOut.capacityAndFlags = newCapacity;
    }
    const int numDistances = distance.getSize();
    distanceOut.size = numDistances;
    hkArrayUtil::copy(distanceOut.data, distance.data, numDistances);

    curve->smoothingFactor = smoothingFactor;
    return curve;
}
