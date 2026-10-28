/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the broad phase layer of each body, from its flags. */
void hknpDefaultBroadPhaseConfig::FUN_00154e10(const hknpBodyId *bodyIds, int numBodyIds,
                                               const hknpBody *bodies, u8 *layersOut) const
{
    for (int i = 0; i < numBodyIds; i++) {
        const int flags = bodies[bodyIds[i].value].flags;
        if (flags & 0x100) {
            layersOut[i] = 1;
        } else if (flags & 0x8) {
            layersOut[i] = 0;
        } else if (flags & 0x1) {
            layersOut[i] = 3;
        } else {
            layersOut[i] = 2;
        }
    }
}
