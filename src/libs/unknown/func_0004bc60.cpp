/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the world's handler of its material library's
 * materialAddedSignal: the material bits grow with the library, the new
 * ones clear. */
void hknpWorld::FUN_0004bc60(hknpMaterialId id)
{
    int numMaterials = materialLibrary->entries.elements.size;
    if (bits660.storage.numBits != numMaterials) {
        bits660.FUN_00047b30(0, numMaterials, 0);
    }
}
