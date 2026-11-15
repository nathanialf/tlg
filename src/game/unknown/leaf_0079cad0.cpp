/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ad9f8.h"

/* derived name: the constructor (tlg_game_object016ad9f8.h): its base
 * Object00774560 is built from the name passed on (FUN_00774370), the Name,
 * the two ints and the reference cleared; then the body: the base's float
 * at +0x7c and two of its own, the Name set to "jt_ProxySamplingA", looked up
 * without interning it (`xor ecx, ecx`), eight floats in one store, the reference emptied again by an
 * exchange, -1.0 at +0x160. */
Object016ad9f8::Object016ad9f8(const Name &name)
    : Object00774560(name), unknown144(0), unknown148(0)
{
    unknown7c = 0.2f;
    unknownf0 = 0.3f;
    unknown140 = 1.0f;
    namefc = Name("jt_ProxySamplingA", false);
    unknown120 = 0.0f;
    unknown124 = 4.9f;
    unknown128 = 0.0f;
    unknown12c = 1.0f;
    unknown130 = 0.0f;
    unknown134 = 0.3f;
    unknown138 = 0.0f;
    unknown13c = 1.0f;
    held158.clear();
    unknown160 = -1.0f;
}

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00774560 runs as a tail call. FUN_0079cbc0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ad9f8::~Object016ad9f8() {}
