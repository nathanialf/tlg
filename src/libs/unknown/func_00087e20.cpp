/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the cleanup callback of hkxVertexBuffer::VertexData's type
 * info (0x57c6970): destroy the object in place through its out-of-line
 * destructor. */
void FUN_00087e20(void *object) /* derived name */
{
    static_cast<hkxVertexBuffer::VertexData *>(object)->~VertexData();
}
