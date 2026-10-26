/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpMotionPropertiesLibrary's finish constructor: the vtable set, the
 * signals empty, the entries left as loaded. */
hknpMotionPropertiesLibrary::hknpMotionPropertiesLibrary(hkFinishLoadedObjectFlag flag)
    : hkReferencedObject(flag), entries(flag)
{
}
