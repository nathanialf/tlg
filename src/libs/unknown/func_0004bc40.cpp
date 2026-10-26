/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the world's handler of its material library's
 * materialModifiedSignal: marks the material's bit at +0x660. */
void hknpWorld::FUN_0004bc40(hknpMaterialId id)
{
    bits660.set(id.value);
}
