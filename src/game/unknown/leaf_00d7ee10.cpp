/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object05945a38.h"

/* derived names: slot 13 of the vtable at 0x16baba8 (its pointer at
 * 0x16bac20; leaf_00d7ee00.cpp has slot 9), called with an object whose
 * counted reference at +0x248 it fills when empty; its own object is not
 * read. Class and method unknown. */
struct Object00d7ee10;

/* derived name: the object slot 13 is given: a counted reference another
 * thread may replace at +0x248; nothing else is traced */
struct Target00d7ee10 /* derived name */
{
    u8 unknown0[0x248];
    AtomicRef0045c470<Object016b9108> held248; /* +0x248 */
};

/* derived name: the type of the object slot 13 makes (`mov rsi,
 * [0x598a048]`) */
extern Type00503fb0 *D_598a048;

/* derived name: the made object's class, one over the reference's (the new
 * pointer compared first after the exchange), with the making as its own
 * inline function: the name's temporary ends inside it, so its release is
 * gone once the call is known not to change it (as Value00d48670's,
 * tlg_game_object016ba510.h); not traced otherwise */
struct Value00d7ee10 : Object016b9108 {
    static Value00d7ee10 *make()
    {
        return static_cast<Value00d7ee10 *>(FUN_00cbc5a0(D_5945a38, D_598a048, Name(), 0));
    }
};

void FUN_00d7ee10(Object00d7ee10 *self, Target00d7ee10 *target) /* derived name */
{
    if (target->held248.get() == 0)
        target->held248.set(Value00d7ee10::make());
}
