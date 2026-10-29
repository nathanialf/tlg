/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the cleanup callback of hknpShapeInstance's type info:
 * destroy the instance in place, which releases its shape's reference. */
void hknpShapeInstance::FUN_0003caa0(void *object)
{
    static_cast<hknpShapeInstance *>(object)->~hknpShapeInstance();
}
