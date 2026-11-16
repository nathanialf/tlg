/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a8688.h"

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_00333200, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a8688::~Object016a8688() {}

/* derived name: the constructor: the base built from the name, the three
 * references empty, then the first two emptied again by exchange, the
 * fields at +0x40 cleared, FUN_00332d10 called and the int at +0x5c
 * cleared. Its creator FUN_00332a20 calls it.
 * NONMATCHING: the build forwards the member-list zero at +0x28 into the
 * first exchange (`xor eax, eax; lock cmpxchg; je`, the exchange peeled);
 * the base reads the pointer again in the loop. Lead: the zero store and the
 * loop's load are of different access types in the original (struct-path
 * TBAA would then keep GVN from forwarding). */
Object016a8688::Object016a8688(const Name &name) : Object016b9108(name), unknown58(0)
{
    held28.clear();
    held30.clear();
    for (int i = 0; i < 4; ++i)
        unknown40[i] = 0;
    unknown50 = 0;
    FUN_00332d10();
    unknown5c = 0;
}
