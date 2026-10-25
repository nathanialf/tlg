/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hknpDefaultBroadPhaseConfig's vtable (address point
 * 0x16a4600) returns the layer at the given index. */
hknpBroadPhaseConfig::Layer *
hknpDefaultBroadPhaseConfig::FUN_00154e00(hkUlong layerIndex) /* derived name */
{
    return &layers[layerIndex];
}
