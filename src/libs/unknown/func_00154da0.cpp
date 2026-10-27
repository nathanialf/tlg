/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The layers in the order the stores take (0x154db5 on): the last, the
 * first, the third, the second. */
hknpDefaultBroadPhaseConfig::hknpDefaultBroadPhaseConfig()
{
    layers[3].collideWithLayerMask = 1;
    layers[3].isVolatile = false;
    layers[0].collideWithLayerMask = 1;
    layers[0].isVolatile = true;
    layers[2].collideWithLayerMask = 1;
    layers[2].isVolatile = false;
    layers[1].collideWithLayerMask = 0;
    layers[1].isVolatile = true;
}
