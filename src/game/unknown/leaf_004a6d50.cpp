/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"

/* derived names: a text of at most 127 characters in a 128-byte buffer and
 * its length at +0x80: formats into it (vsnprintf with 0x7f), the length the
 * one vsnprintf returns, 127 when it fails; unlike its siblings (FUN_01331920)
 * the last byte is not cleared first. Its one caller is FUN_00489c30. */
struct Text004a6d50 {                     /* derived name */
    void format(const char *format, ...); /* derived name */

    char text[0x80];
    int length; /* +0x80 */
};

void Text004a6d50::format(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int written = vsnprintf(text, sizeof text - 1, format, args);
    va_end(args);
    length = written < 0 ? sizeof text - 1 : written;
}
