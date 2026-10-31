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

/* The record's constructor: no body, on no list, no flags (0x1618f0). */
hknpBodyManager::ScheduledBodyChange::ScheduledBodyChange()
    : bodyId(0x7fffffff), listIndex(0x7fffffff)
{
    flags = 0;
}

void hknpBodyManager::FUN_00161790(const hknpBodyId *bodyIds, int numBodyIds, u16 kind)
{
    hkArray<u32> *list = kind == 1 ? &bodiesOfChange1 : kind == 2 ? &bodiesOfChange2 : HK_NULL;
    for (int i = 0; i < numBodyIds; i++) {
        const u32 bodyId = bodyIds[i].value;
        int &index = scheduledBodyChangeIndices[bodyId];
        ScheduledBodyChange *change;
        if (index == 0x7fffffff) {
            index = scheduledBodyChanges.getSize();
            change = new (&scheduledBodyChanges.expandOneUnconstructed()) ScheduledBodyChange();
            change->bodyId = bodyId;
        } else {
            change = &scheduledBodyChanges[index];
        }
        change->listIndex = list->getSize();
        change->flags |= kind;
        list->pushBack(bodyId);
    }
}
