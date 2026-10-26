/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpDefaultBroadPhaseConfig's finish constructor: the layers are loaded
 * in place, so only the vtable is set. */
hknpDefaultBroadPhaseConfig::hknpDefaultBroadPhaseConfig(hkFinishLoadedObjectFlag flag)
    : hknpBroadPhaseConfig(flag)
{
}
