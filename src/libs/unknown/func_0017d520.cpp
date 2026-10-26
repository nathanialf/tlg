/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The flags and the keyframe are left as loaded; the node name's finish
 * constructor is out of line. */
hkAlignSceneToNodeOptions::hkAlignSceneToNodeOptions(hkFinishLoadedObjectFlag flag)
    : hkReferencedObject(flag)
{
    FUN_0000e5c0(&nodeName, flag);
}
