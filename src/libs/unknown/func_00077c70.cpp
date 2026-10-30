/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpMaterialLibrary::FUN_00077c70(hknpMaterialId id)
{
    materialRemovedSignal.fire(id);
    entries.release(id);
}
