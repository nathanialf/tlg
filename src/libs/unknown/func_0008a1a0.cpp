/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The vertex data's arrays are left as loaded; the description's finish
 * constructor is out of line. The vtable, and with it the inline destructor's
 * complete and deleting variants (0x89fd0, 0x8a080), are emitted here. */
hkxVertexBuffer::hkxVertexBuffer(hkFinishLoadedObjectFlag flag)
    : hkReferencedObject(flag), data(flag), desc(flag)
{
}
