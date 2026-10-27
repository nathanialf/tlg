/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkxNode::hkxNode(hkFinishLoadedObjectFlag flag)
    : hkxAttributeHolder(flag), keyFrames(flag), children(flag), annotations(flag),
      linearKeyFrameHints(flag)
{
    FUN_0000e5c0(&name, flag);
    FUN_0000dbc0(&uuid, flag);
    FUN_0000e5c0(&userProperties, flag);
}
