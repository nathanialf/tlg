/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ad930.h"

/* derived name: the constructor (tlg_game_object016ad930.h): its base
 * Object00774560 is built from the name passed on (FUN_00774370), the Name
 * and the two links cleared; then the body: the base's float at +0x7c, the
 * Name set to "jt_ProxySamplingA", looked up without interning it (`xor ecx,
 * ecx`), and each link reset. */
Object016ad930::Object016ad930(const Name &name) : Object00774560(name)
{
    unknown7c = 0.2f;
    namefc = Name("jt_ProxySamplingA", false);
    link100.reset();
    link130.reset();
}

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00774560 runs as a tail call. FUN_0079af20, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ad930::~Object016ad930() {}

/* derived name: slot 14: when slot 22 allows it, the body at +0x68 turned
 * and moved by the pose as Object016ad2f0's slot 14 does (FUN_0077bac0),
 * then the point at +0x120 (the first link's) set: the pose's point at +0xe0 moved by the
 * body's position and by the point at +0x150 (the second link's) turned by the product of the
 * pose's rotation at +0xd0 and the body's (that point's w the pose's) */
void Object016ad930::slot14(Pose0077bac0 *pose)
{
    if (slot22()) {
        follow(pose);
        const Float4A turn = FUN_013439c0(pose->rotationd0, unknown68->rotation);
        link100.unknown20 = pose->pointe0 + Vector0077bac0(unknown68->position) +
                            FUN_01343bb0(link130.unknown20, turn);
    }
}
