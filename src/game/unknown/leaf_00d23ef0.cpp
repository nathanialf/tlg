/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_object016ba190.h"

/* derived name: every object of the class, under the array's lock: the
 * constructor FUN_00d23490 appends the object (0xd236e4 to 0xd23784), its
 * destructor FUN_00d237d0 takes it out (0xd238e0 to 0xd23918) */
extern Array01343a80<Object016ba190 *> D_5948488;

/* derived name: calls the callback with each object of the class and the
 * context, first to last, under the array's lock, until one returns 0 (the
 * caller at 0xd387ba passes 0x13b7610 and an object of its own, as it
 * passes others to FUN_00cb8790 for the objects of a type) */
void FUN_00d23ef0(int (*callback)(Object016ba190 *object, void *context),
                  void *context) /* derived name */
{
    D_5948488.lock.lock();
    for (Object016ba190 *object : D_5948488) {
        if (!callback(object, context))
            break;
    }
    D_5948488.lock.unlock();
}
