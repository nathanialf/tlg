/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Whether a key names a live body (bit 0 or 1 of its flags) whose own key
 * is the same. derived name. */
static inline bool isValidKey(const hknpWorld *world, const BodyKey0016e040 &key) /* derived name */
{
    const int bodyId = key.bodyId;
    if (bodyId == 0x7fffffff) {
        return false;
    }
    if (u32(world->bodyManager.bodies.getCapacity()) <= u32(bodyId)) {
        return false;
    }
    const hknpBody &body = world->bodyManager.bodies.data[bodyId];
    if (!(body.flags & 3)) {
        return false;
    }
    return ((u64(body.id) << 32) | body.byte7f) == key.key;
}

bool WorldReference0016e040::FUN_0016e040(const BodyKey0016e040 *pair) const
{
    return isValidKey(world, pair[0]) && isValidKey(world, pair[1]);
}
