/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"

/* derived names: hands every element of the locked array at +0x10 of the
 * object at +0x120 of the one the pointer at 0x57c9390 holds to
 * FUN_00b47ac0, under the array's lock (the count read again after each
 * call). The classes and what the callee does are not traced. */
struct Element013400f0; /* derived name */

struct List013400f0 { /* derived name */
    u8 unknown0[0x10];
    Array01343a80<Element013400f0 *> elements; /* +0x10 */
};

struct Object057c9390 { /* derived name: the object, seen from here */
    u8 unknown0[0x120];
    List013400f0 *unknown120; /* +0x120 */
};

extern Object057c9390 *D_57c9390;

void FUN_00b47ac0(Element013400f0 *element); /* derived name */

void FUN_013400f0() /* derived name */
{
    List013400f0 *list = D_57c9390->unknown120;
    list->elements.lock.lock();
    for (unsigned i = 0; i < list->elements.size(); ++i)
        FUN_00b47ac0(list->elements.at(i));
    list->elements.lock.unlock();
}
