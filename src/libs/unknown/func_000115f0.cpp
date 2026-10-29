/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The buffer of a C string, a null one read as empty: its characters and
 * terminator in the buffer's own storage while they fit, grown from the
 * temporary allocator beyond. */
hkStringBuf::hkStringBuf(const char *s)
{
    if (s != 0) {
        const int length = FUN_00017fe0(s);
        string.setSize(hkContainerTempAllocator::get(), length + 1);
        string[length] = 0;
        FUN_00017e70(string.data, s, length);
    } else {
        string.setSize(hkContainerTempAllocator::get(), 1);
        string[0] = 0;
    }
}
