/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"
#include "tlg_libc.h"

/* derived names: the script compiler's formatter of its messages into a
 * buffer: vsprintf over the arguments after the format; the buffer's size
 * its callers pass is not used (they do not set it: the link drops it) */
int FUN_00d95b60(char *buffer, size_t size, const char *format, ...) /* derived name */
{
    va_list args;
    va_start(args, format);
    int length = vsprintf(buffer, format, args);
    va_end(args);
    return length;
}
