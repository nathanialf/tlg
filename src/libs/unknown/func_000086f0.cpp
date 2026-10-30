/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Formatted into a buffer on the stack, then written whole. */
void hkOstream::FUN_000086f0(const char *format, ...)
{
    char buffer[10024];
    va_list args;
    va_start(args, format);
    FUN_00017e20(buffer, sizeof(buffer), format, args);
    va_end(args);
    writer->write(buffer, FUN_00017fe0(buffer));
}
