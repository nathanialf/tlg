/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int FUN_00017e20(char *buffer, int size, const char *format, va_list args) /* derived name */
{
    va_list copy;
    va_copy(copy, args);
    const int result = vsnprintf(buffer, size, format, copy);
    va_end(copy);
    return result;
}
