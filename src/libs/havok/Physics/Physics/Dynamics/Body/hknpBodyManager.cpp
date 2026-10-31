/* src/libs/havok/Physics/Physics/Dynamics/Body/hknpBodyManager.cpp:
 * the file its report names (config/homes.base.txt, FUN_001607c0). */
#include "tlg_lib_unknown.h"

u32 hknpBodyManager::FUN_001607c0()
{
    const u32 bodyId = firstFreeBodyId;
    if (bodyId == 0x7fffffff) {
        HK_ERROR(0x506609a5, HK_NP_BODY_MANAGER_CPP, 258, "Body buffer is full.");
        return 0x7fffffff;
    }
    firstFreeBodyId = bodies[bodyId].nextFreeBodyId();
    numBodies98++;
    peakBodyId = hkMath::max2(peakBodyId, bodyId);
    const u8 generation = bodies[bodyId].byte7f;
    hkString::memSet16(&bodies[bodyId], &D_14b2060[2], sizeof(hknpBody) / 16);
    bodies[bodyId].byte7f = generation + 1;
    bodies[bodyId].id = bodyId;
    activeBodyCellIndices[bodyId] = 0xff;
    fieldMap.FUN_001997d0(bodyId);
    return bodyId;
}
