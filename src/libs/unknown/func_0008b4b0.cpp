/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkxNode::hkxNode(hkFinishLoadedObjectFlag flag)
    : hkxAttributeHolder(flag), name(flag), uuid(flag), keyFrames(flag), children(flag),
      annotations(flag), linearKeyFrameHints(flag), userProperties(flag)
{
}
