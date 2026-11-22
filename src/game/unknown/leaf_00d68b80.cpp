/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00d68b80.h"

/* derived name: the object's reference made for the call, the array
 * searched and appended to under it, dropped before the flag is set */
// NONMATCHING: the count's address at the release: the base reads it as `cmp [r12 + 8]` and
// drops through r15 (the address CodeGenPrepare sinks into the load, round 325C's class);
// the build reads it through r15. 95 of 100 equal.
void Object00d68b80::add(Object016b9108 *object)
{
    if (object == 0)
        return;
    link(AtomicRef0045c470<Object016b9108>(object));
    flags20 |= 1;
}
