/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ad548.h"

/* derived name: the constructor (tlg_game_object016ad548.h): its base
 * Object00774560 is built from the name passed on (FUN_00774370), the Names
 * and the link cleared; then the body: the base's float at +0x7c, the Name
 * at +0xfc set to "jt_ProxySamplingA", interned as a copy (`xor
 * ecx, ecx`), and the link reset. */
Object016ad548::Object016ad548(const Name &name) : Object00774560(name)
{
    unknown7c = 0.2f;
    namefc = Name("jt_ProxySamplingA", false);
    link100.reset();
}

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00774560 runs as a tail call. FUN_0078e140, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ad548::~Object016ad548() {}

/* derived name: slot 14: the body at +0x68 turned and moved by the pose
 * (Object00774560::follow), then the ints at +0x3c and +0x40 set to whether
 * a member of the pose's group has this object's name (the count read once,
 * `test eax, eax; je` before the search; a member at a signed index) */
void Object016ad548::slot14(Pose0077bac0 *pose)
{
    follow(pose);
    int found = 0;
    if (const Group00790150 *group = pose->group) {
        for (unsigned i = 0; i < group->members.size(); ++i) {
            if (group->members.at(i)->name == namee0) {
                found = 1;
                break;
            }
        }
    }
    unknown3c = found;
    unknown40 = found;
}
