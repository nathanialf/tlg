/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkxMaterialEffect's type info
 * (registered at 0x89e5f): construct the object in place from a loaded image. */
void FUN_00089c70(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxMaterialEffect(flag);
}
