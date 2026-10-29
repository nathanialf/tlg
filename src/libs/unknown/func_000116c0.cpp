/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkStringBuf &FUN_000116c0(hkStringBuf *self, const char *string) /* derived name */
{
    if (string != 0) {
        const int length = FUN_00017fe0(string);
        self->string.setSize(hkContainerTempAllocator::get(), length + 1);
        self->string[length] = 0;
        FUN_00017e70(self->string.data, string, length);
    } else {
        self->string.setSize(hkContainerTempAllocator::get(), 1);
        self->string[0] = 0;
    }
    return *self;
}
