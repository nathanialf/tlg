/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 9: the position set from the start, moved from where it is or set
 * back from the end; any other origin leaves it. The end follows it, and
 * the seek always succeeds. */
hkResult OffsetOnlyStreamWriter::seek(int relativeOffset, int whence)
{
    if (whence == 0) {
        offset = relativeOffset;
    } else if (whence == 1) {
        offset += relativeOffset;
    } else if (whence == 2) {
        offset = end - relativeOffset;
    }
    end = offset > end ? offset : end;
    return HK_SUCCESS;
}
