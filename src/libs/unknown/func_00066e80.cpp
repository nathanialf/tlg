/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpMaterialDescriptor::FUN_00066e80(void *object)
{
    static_cast<hknpMaterialDescriptor *>(object)->~hknpMaterialDescriptor();
}
