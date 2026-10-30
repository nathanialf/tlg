/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpTyremarksInfo::FUN_00069150(const hknpVehicleInstance *vehicle, int wheel,
                                     Vec4 *stripsOut) const
{
    const hknpTyremarksWheel &tyremarks = *tyremarksWheel.data[wheel];
    const int numPoints = tyremarks.numPoints;
    for (int i = 0; i < numPoints; i++) {
        const hknpTyremarkPoint &point = tyremarks.getTyremarkPoint(i);
        stripsOut[i * 2] = point.pointLeft;
        stripsOut[i * 2 + 1] = point.pointRight;
    }
}
