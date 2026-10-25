/* src/libs/havok/Physics/Physics/Dynamics/World/hknpWorld.cpp:
 * the file its assert names (config/homes.base.txt, FUN_0004d0a0). */
#include "tlg_hk_reflect.h"

/* derived name: sets the world's collision filter, held by the object at
 * +0x1b8 (the world's own constructor does the same at 0x4a1a7; the game
 * calls this at 0xea98cc). FUN_0004bcc0 sits between the constructor
 * FUN_00048b20 and the homed FUN_0004d0a0, all three on the same object. */
void hknpWorld::FUN_0004bcc0(hknpCollisionFilter *filter) /* derived name */
{
    modifierManager->FUN_000667b0(filter);
}

/* derived name: the signal of a world event type for one body, from the
 * event dispatcher at +0x6c8. */
hknpEventSignal *hknpWorld::FUN_0004fbd0(int eventType, int bodyId) /* derived name */
{
    return eventDispatcher->FUN_0006bdf0(eventType, bodyId);
}

/* derived name: the signal of a world event type, from the event dispatcher
 * at +0x6c8. */
hknpEventSignal *hknpWorld::FUN_0004fbe0(int eventType) /* derived name */
{
    return eventDispatcher->FUN_0006bf60(eventType);
}

/* derived name: the pointer at +0x10 of the world's object at +0x1d0
 * (called at 0x177435). */
void *hknpWorld::FUN_00051610() const /* derived name */
{
    return object1d0->pointer10;
}
