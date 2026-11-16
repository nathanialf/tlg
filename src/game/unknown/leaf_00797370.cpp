/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ad7a0.h"

/* derived name: the constructor (tlg_game_object016ad7a0.h): its base
 * Object00774560 is built from the name passed on (FUN_00774370), the Name
 * and the two links cleared; then the body: the base's float at +0x7c, the
 * Name set to "jt_ProxySamplingA", looked up without interning it (`xor ecx,
 * ecx`), each link reset, then the fields from +0x160. */
Object016ad7a0::Object016ad7a0(const Name &name) : Object00774560(name)
{
    unknown7c = 0.2f;
    namefc = Name("jt_ProxySamplingA", false);
    link100.reset();
    link130.reset();
    unknown160 = 0;
    unknown164 = 0;
    unknown168 = 45.0f;
    unknown16c = 0.001f;
    unknown174 = 1;
}

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00774560 runs as a tail call. FUN_007974e0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ad7a0::~Object016ad7a0() {}

/* derived name: slot 14: when slot 22 allows it, the body put back home
 * (Object00774560::goHome); held, the int at +0x160 set to 1, else turned
 * by the pose and moved by the pose's position less the body's vector at
 * +0x1440; then the first link's point set as Object016ace40's slot 14 sets
 * its own (FUN_00777b10) and copied to the body's +0x5060 */
void Object016ad7a0::slot14(Pose0077bac0 *pose)
{
    if (slot22()) {
        goHome();
        if (unknown68->unknown1330) {
            unknown160 = 1;
        } else {
            unknown68->turn(pose->rotation);
            unknown68->move(pose->position - unknown68->unknown1440);
        }
        const Float4A turn = FUN_013439c0(pose->rotationd0, unknown68->rotation);
        link100.unknown20 = pose->pointe0 + Vector0077bac0(unknown68->position) +
                            FUN_01343bb0(link130.unknown20, turn);
        unknown68->unknown5060 = link100.unknown20;
    }
}
