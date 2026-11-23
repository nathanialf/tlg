/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_string01331840.h"
#include "tlg_libc.h"
#include <stdarg.h>

/* derived name: the text (tlg_game_string01331840.h) formatted from the
 * arguments, at most 0xfff characters, the length the one vsnprintf gives
 * or 0xfff when it fails (`cmovns`); unlike FUN_01331840 the last byte is
 * not cleared first (FUN_00315bf0 formats with it) */
void FUN_00317070(String01331840 *string, const char *format, ...)
{
    va_list arguments;
    va_start(arguments, format);
    const int length = vsnprintf(string->text, 0xfff, format, arguments);
    string->length = length < 0 ? 0xfff : length;
    va_end(arguments);
}
