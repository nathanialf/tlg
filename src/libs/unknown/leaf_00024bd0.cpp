/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hkMultipleVertexBuffer's vtable (address point 0x1692000)
 * tells whether the buffer is sharable. */
bool hkMultipleVertexBuffer::FUN_00024bd0() const /* derived name */
{
    return isSharable;
}
