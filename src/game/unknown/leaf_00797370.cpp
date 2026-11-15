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
