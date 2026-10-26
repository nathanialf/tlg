/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 3 of the world's material slot calls its member
 * function on the world it was subscribed for. */
void hknpWorldMaterialSlot::FUN_00047d90(hknpMaterialId id)
{
    (static_cast<hknpWorld *>(object)->*method)(id);
}
