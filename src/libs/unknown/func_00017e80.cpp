/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"
#include "tlg_libc.h"

int FUN_00017e80(char *buffer, int size, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    const int result = vsnprintf(buffer, size, format, args);
    va_end(args);
    return result;
}
