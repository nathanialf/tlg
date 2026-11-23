/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"

/* derived name: formats a message into a 2048-byte buffer with vsprintf_s
 * and prints it with puts (FUN_01303110 reports a stalled compute context
 * through it) */
void FUN_00f1a460(const char *format, ...) /* derived name */
{
    char text[0x800];
    va_list args;
    va_start(args, format);
    vsprintf_s(text, sizeof(text), format, args);
    puts(text);
    va_end(args);
}
