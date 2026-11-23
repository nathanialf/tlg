/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_string01331840.h"
#include "tlg_libc.h"
#include <stdarg.h>

/* derived name: the arguments formatted after the text
 * (tlg_game_string01331840.h) while it has room, at most 0xfff characters in
 * all: the length grows by what vsnprintf gives, or becomes 0xfff when it
 * fails */
void FUN_01346a00(String01331840 *string, const char *format, ...)
{
    if (unsigned(string->length) >= 0xfff)
        return;
    va_list arguments;
    va_start(arguments, format);
    const unsigned used = string->length;
    const int added = vsnprintf(string->text + used, 0xfff - used, format, arguments);
    int length = 0xfff;
    if (added >= 0)
        length = string->length + added;
    string->length = length;
    va_end(arguments);
}
