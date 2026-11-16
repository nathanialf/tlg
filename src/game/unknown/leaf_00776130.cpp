/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ace40.h"

/* derived name: the constructor (tlg_game_object016ace40.h): its base
 * Object00774560 is built from the name passed on (FUN_00774370), the Name,
 * the pointers and the references start empty (a 20-byte clear at +0xfc, 16
 * bytes at +0x130); then the body: the base's float at +0x7c set to 0.2, the
 * Name set to "jt_ProxySamplingA" (the string at 0x1595794, its length 17
 * passed, not added), and each reference emptied by compare-and-swap with
 * the fields after it set, the one at +0x108 first. */
// NONMATCHING: the two zero runs of the member list are cleared in the other order in the base (16 bytes at +0x130 before the 20 at +0xfc; one MemCpyOpt scan gives them in address order, cookbook 2143): the source form not found
Object016ace40::Object016ace40(const Name &name)
    : Object00774560(name), unknown100(0), unknown130(0)
{
    unknown7c = 0.2f;
    namefc = Name("jt_ProxySamplingA", false);
    held108.clear();
    unknown100 = 0;
    unknown110 = 0;
    unknown120 = Float4A(0.0f, 0.0f, 0.0f, 1.0f);
    held138.clear();
    unknown130 = 0;
    unknown140 = 0;
    unknown150 = Float4A(0.0f, 0.0f, 0.0f, 1.0f);
}

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00774560 runs as a tail call. FUN_007762a0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ace40::~Object016ace40() {}

/* derived name: slot 14: when slot 22 allows it, the body at +0x68 turned
 * and moved by the pose as Object016ad2f0's slot 14 does (FUN_0077bac0),
 * then the point at +0x120 set: the pose's point at +0xe0 moved by the
 * body's position and by the point at +0x150 turned by the product of the
 * pose's rotation at +0xd0 and the body's (that point's w the pose's) */
void Object016ace40::slot14(Pose0077bac0 *pose)
{
    if (slot22()) {
        follow(pose);
        const Float4A turn = FUN_013439c0(pose->rotationd0, unknown68->rotation);
        unknown120 =
            pose->pointe0 + Vector0077bac0(unknown68->position) + FUN_01343bb0(unknown150, turn);
    }
}
