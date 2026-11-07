/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The buffer's length set: the characters and the terminator, the
 * terminator stored (Havok's hkStringBuf::setLength). derived name. */
static inline void setLength(hkStringBuf *self, int length)
{
    self->string.setSize(hkContainerTempAllocator::get(), length + 1);
    self->string[length] = 0;
}

/* derived name: formatted into the buffer, printf style: tried at the
 * buffer's capacity, the buffer doubled (at least 255 characters) while
 * the formatter only reports failure, set to the length it reports when
 * that is too long, and to the written length once it fits. */
void FUN_00011900(hkStringBuf *self, const char *format, ...)
{
    va_list args;
    for (;;) {
        va_start(args, format);
        const int size = self->string.getCapacity();
        const int numChars = FUN_00017e20(self->string.data, size, format, args);
        va_end(args);
        if (numChars >= 0 && numChars < size) {
            setLength(self, numChars);
            break;
        } else if (numChars < 0) {
            setLength(self, size * 2 > 255 ? size * 2 : 255);
        } else {
            setLength(self, numChars);
        }
    }
}
