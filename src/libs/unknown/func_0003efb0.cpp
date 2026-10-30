/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void FUN_0003efb0(void *object) /* derived name */
{
    typedef hkFreeListArray<hknpShapeInstance, hknpShapeInstanceId, 8, hknpShapeInstance>
        InstanceArray;
    static_cast<InstanceArray *>(object)->~InstanceArray();
}
