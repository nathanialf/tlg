/* src/libs/havok/Physics/Physics/Collide/Dispatcher/hknpCollisionDispatcher.cpp:
 * the file its report names (config/homes.base.txt, FUN_00174050). */
#include "tlg_lib_unknown.h"

/* The file this one's reports name (the string at 0x14caed4). */
#define HK_NP_COLLISION_DISPATCHER_CPP                                                             \
    "Y:\\NightlyJobs\\20141121-01\\Source\\Physics\\Physics\\Collide\\Dispatcher\\"                \
    "hknpCollisionDispatcher.cpp"

/* derived name: the dispatcher's default cache creator, which the
 * dispatcher's constructor (0x173f90) puts in every slot of its table no
 * shape pair registers: it reports the dispatch and creates nothing. */
void FUN_00174050()
{
    HK_ERROR(0x30ff763a, HK_NP_COLLISION_DISPATCHER_CPP, 27, "Unregistered cache creator dispatch");
}

hknpCollisionDispatcher::hknpCollisionDispatcher()
{
    maxCacheSize = 0x50;
    for (int i = 0; i < hknpCollisionDispatchType::NUM_TYPES; i++) {
        for (int j = 0; j < hknpCollisionDispatchType::NUM_TYPES; j++) {
            dispatchTable[i][j] = FUN_00174050;
        }
    }
    for (int i = 0; i < hknpCollisionDispatchType::NUM_TYPES; i++) {
        registerCacheCreator(hknpCollisionDispatchType::NONE, hknpCollisionDispatchType::Enum(i),
                             FUN_0016a370);
    }
    registerCacheCreator(hknpCollisionDispatchType::CONVEX, hknpCollisionDispatchType::CONVEX,
                         FUN_00179c80);
    registerCacheCreator(hknpCollisionDispatchType::CONVEX, hknpCollisionDispatchType::COMPOSITE,
                         FUN_00199b00);
    registerCacheCreator(hknpCollisionDispatchType::COMPOSITE, hknpCollisionDispatchType::COMPOSITE,
                         FUN_00199970);
    registerCacheCreator(hknpCollisionDispatchType::CONVEX,
                         hknpCollisionDispatchType::DISTANCE_FIELD, FUN_001743b0);
    registerCacheCreator(hknpCollisionDispatchType::COMPOSITE,
                         hknpCollisionDispatchType::DISTANCE_FIELD, FUN_001743b0);
}
