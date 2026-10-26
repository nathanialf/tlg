/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The order the locked elements are sorted in: by vertex buffer, and by
 * element within one buffer. */
bool hkMultipleVertexBuffer::FUN_00024b60(const LockedElement &a,
                                          const LockedElement &b) /* derived name */
{
    if (a.vertexBufferIndex != b.vertexBufferIndex) {
        return a.vertexBufferIndex < b.vertexBufferIndex;
    }
    return a.elementIndex < b.elementIndex;
}
