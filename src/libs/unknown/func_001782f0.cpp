/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the proxy's handler of the world's signal at +0x5f0:
 * when its body carries flag 8, the contacts are dropped. */
void hknpCharacterProxy::FUN_001782f0(hknpWorld *world)
{
    if (world->bodies[bodyId].flags & 8) {
        contacts.clear();
    }
}
