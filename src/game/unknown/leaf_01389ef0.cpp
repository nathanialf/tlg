/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"

/* derived names: a text of at most 31 characters in a 32-byte buffer
 * and its length at +0x20: formats into it (vsnprintf), its last byte
 * cleared first, the length the one vsnprintf returns, 31 when it
 * fails */
struct Text01389ef0 {                     /* derived name */
    void format(const char *format, ...); /* derived name */

    char text[0x20];
    int length; /* +0x20 */
};

void Text01389ef0::format(const char *format, ...)
{
    text[sizeof text - 1] = '\0';
    va_list args;
    va_start(args, format);
    int written = vsnprintf(text, sizeof text - 1, format, args);
    va_end(args);
    length = written < 0 ? sizeof text - 1 : written;
}
