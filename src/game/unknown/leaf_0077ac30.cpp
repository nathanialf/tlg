/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ad2f0.h"

/* derived name: the constructor (tlg_game_object016ad2f0.h): its base
 * Object00774560 is built from the name passed on (FUN_00774370), the Name,
 * the pointers and the references start empty (a 20-byte clear at +0xfc, 16
 * bytes at +0x130); then the body: the base's float at +0x7c set to 0.2, the
 * Name set to "jt_ProxySamplingA" (the string at 0x1595794, its length 17
 * passed, not added), and each reference emptied by compare-and-swap with
 * the fields after it set, the one at +0x108 first. */
// NONMATCHING: the two zero runs of the member list are cleared in the other order in the base (16 bytes at +0x130 before the 20 at +0xfc; one MemCpyOpt scan gives them in address order, cookbook 2143): the source form not found
Object016ad2f0::Object016ad2f0(const Name &name)
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
}

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00774560 runs as a tail call. FUN_0077ada0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ad2f0::~Object016ad2f0() {}
