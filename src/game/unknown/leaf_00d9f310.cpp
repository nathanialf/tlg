/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived name: reads a string of `length` characters as a number (Lua's
 * str2d over a counted string): the decimal reading, then a hexadecimal one
 * where it stops at an 'x', then the spaces after it skipped; nonzero when
 * the reading ends at the string's end (called by FUN_00db6f40, FUN_00db70c0
 * and eleven more) */
int FUN_00d9f310(const char *data, u64 length, float *number) /* derived name */
{
    char *end;
    *number = strtod(data, &end);
    if (end == data)
        return 0;
    if (*end == 'x' || *end == 'X')
        *number = _Stoul(data, &end, 16);
    while (isspace(static_cast<unsigned char>(*end)))
        ++end;
    return data + length == end;
}
