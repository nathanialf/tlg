/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Out of line: the finish callback 0x22fb0 jumps here. */
hkMemoryMeshBody::hkMemoryMeshBody(hkFinishLoadedObjectFlag flag)
    : hkMeshBody(flag), vertexBuffers(flag), name(flag)
{
}
