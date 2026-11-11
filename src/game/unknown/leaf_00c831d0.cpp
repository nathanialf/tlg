/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_log.h"
#include "tlg_libc.h"

/* derived names: formats the message into a 4 KiB buffer whose last four
 * bytes hold "..." (a message vsnprintf cuts short ends with the dots), a
 * failed format sending the whole buffer, then writes it to the game's
 * output on channel 0; a null format writes nothing. */
// NONMATCHING: list-ilp order, the base tests the length (`test eax, eax`) before
// `mov ecx, 0xfff`, the build after; and the base's one-byte nop after the call
// of __stack_chk_fail that ends the function (D26, the library line's backport only).
void FUN_00c831d0(const void *, const char *format, ...)
{
    if (format) {
        char text[0x1000];
        strcpy(&text[sizeof text - 4], "...");
        va_list args;
        va_start(args, format);
        int length = vsnprintf(text, sizeof text - 4, format, args);
        va_end(args);
        if (length < 0) {
            length = sizeof text - 1;
        }
        debugOutput().write(0, text, length);
    }
}
