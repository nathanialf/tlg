/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016a9800.h"
#include "tlg_game_object05945a38.h"

/* derived name: the type of the object the constructor makes */
extern Type00503fb0 *D_57d2a68;

/* derived name: the made object's class, one over the reference's (the
 * new pointer compared first after the exchange), with the making as its
 * own inline function (as Value006910d0's, leaf_006910d0.cpp); not traced
 * otherwise */
struct Value00407ab0 : Object016b9108 {
    static Value00407ab0 *make()
    {
        return static_cast<Value00407ab0 *>(FUN_00cbc5a0(D_5945a38, D_57d2a68, Name(), 0));
    }
};

/* the base built from the name, the reference and the two arrays empty,
 * the reference set to an object of the type at 0x57d2a68 made under the
 * empty name (mode 0), 25 at +0x68 */
Object016a9800::Object016a9800(const Name &name) : Object016b9108(name), unknown48(0)
{
    held28.set(Value00407ab0::make());
    unknown68 = 25.0f;
}

/* the complete destructor: the body is empty; the members are released,
 * last first, then the base. FUN_00407f50, slot 1, is the deleting one. */
Object016a9800::~Object016a9800() {}
