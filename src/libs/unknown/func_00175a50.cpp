/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The transform and the flags are left as loaded; the uuid's finish
 * constructor is out of line. */
hknpDestructionShapeProperties::hknpDestructionShapeProperties(hkFinishLoadedObjectFlag flag)
    : hkReferencedObject(flag)
{
    FUN_0000dbc0(&sceneNodeUuid, flag);
}
