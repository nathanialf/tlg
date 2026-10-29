/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The arrays are left as loaded; the name's finish constructor is out of
 * line. */
hknpPhysicsSystemData::hknpPhysicsSystemData(hkFinishLoadedObjectFlag flag)
    : hkReferencedObject(flag), materials(flag), motionProperties(flag), motionCinfos(flag),
      bodyCinfos(flag), constraintCinfos(flag), referencedObjects(flag), name(flag)
{
}
