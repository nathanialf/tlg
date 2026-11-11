/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"

/* derived names: a print callback whose output goes nowhere: it formats the
 * message into a 1 KiB buffer with vsnprintf and returns 0. Its address is
 * stored at +0x120 of the settings record built on the stack at 0xe5cb1c,
 * the format and the argument list being the callback's two parameters (the
 * record fixes the signature). */
int FUN_00e5d120(const char *format, va_list args) /* derived name */
{
    char text[0x400];
    vsnprintf(text, sizeof text, format, args);
    return 0;
}
