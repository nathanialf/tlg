/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016adb88.h"

/* derived name: the constructor (tlg_game_object016adb88.h): its base
 * Object00774560 is built from the name passed on (FUN_00774370), the Name
 * and the two references start empty (one 20-byte clear at +0xfc); then the
 * body: the base's float at +0x7c set to 0.2, and the Name set to
 * "jt_ProxySamplingA" (the string at 0x1595794, its length 17 passed, not
 * added: `mov edx, 0x11; xor ecx, ecx`). */
Object016adb88::Object016adb88(const Name &name) : Object00774560(name)
{
    unknown7c = 0.2f;
    namefc = Name("jt_ProxySamplingA", false);
}

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00774560 runs as a tail call. FUN_0079fdb0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016adb88::~Object016adb88() {}

/* derived name: slot 14: when slot 22 allows it, the body put back home,
 * then turned and moved by the pose unless it is held
 * (Object00774560::followFromHome) */
void Object016adb88::slot14(Pose0077bac0 *pose)
{
    if (slot22())
        followFromHome(pose);
}
