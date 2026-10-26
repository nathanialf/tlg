/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The compound's members are finished by hknpCompoundShape's constructor;
 * the dynamic shape adds only its vtable. */
hknpDynamicCompoundShape::hknpDynamicCompoundShape(hkFinishLoadedObjectFlag flag)
    : hknpCompoundShape(flag)
{
}
