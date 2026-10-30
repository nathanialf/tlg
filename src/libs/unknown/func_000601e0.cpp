/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpWorld::FUN_000601e0(hknpBodyId bodyId, u32 flags, int rebuildMode)
{
    hknpBody &body = bodyManager.bodies[bodyId.value];
    const u32 newFlags = flags & ~0xfu;
    if ((body.flags & newFlags) != newFlags) {
        body.flags |= newFlags;
        object1e0->unknownVirtual4(&bodyId, 1, sizeof(hknpBodyId));
        if (rebuildMode == 0) {
            FUN_0005bf80(bodyId.value);
        }
        signals.bodyChangedSignal.fire(this, bodyId.value);
    }
}
