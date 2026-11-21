/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"

/* derived names: a text of at most 63 characters in a 64-byte buffer
 * and its length at +0x40: formats into it (vsnprintf), its last byte
 * cleared first, the length the one vsnprintf returns, 63 when it
 * fails */
struct Text0136fd80 {                     /* derived name */
    void format(const char *format, ...); /* derived name */

    char text[0x40];
    int length; /* +0x40 */
};

void Text0136fd80::format(const char *format, ...)
{
    text[sizeof text - 1] = '\0';
    va_list args;
    va_start(args, format);
    int written = vsnprintf(text, sizeof text - 1, format, args);
    va_end(args);
    length = written < 0 ? sizeof text - 1 : written;
}
