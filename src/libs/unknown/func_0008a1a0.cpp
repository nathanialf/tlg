/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The vertex data's arrays are left as loaded; the description's finish
 * constructor is out of line. */
hkxVertexBuffer::hkxVertexBuffer(hkFinishLoadedObjectFlag flag)
    : hkReferencedObject(flag), data(flag), desc(flag)
{
}
