/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_libc.h"

/* derived names: the object of FUN_007ff7e0's six calls (0x7ff8f4
 * and on): the one-bit flag 3 of its byte at +0x2e94
 * (`test byte, 8`) turns its log on */
struct Object007f3190 { /* derived name */
    void FUN_007f3190(const char *format, ...);

    u8 unknown0[0x2e94];
    bool unknown2e94_0 : 1;
    bool unknown2e94_1 : 1;
    bool unknown2e94_2 : 1;
    bool unknown2e94_3 : 1;
};

/* derived names: the object's log: with the flag set the message is
 * formatted into a buffer of 256 bytes (at most 255 characters, the last
 * byte cleared when vsnprintf fails), and the buffer goes nowhere: the
 * output is not in the retail executable */
void Object007f3190::FUN_007f3190(const char *format, ...)
{
    if (unknown2e94_3) {
        va_list args;
        char text[0x100];
        va_start(args, format);
        if (vsnprintf(text, sizeof text - 1, format, args) < 0)
            text[sizeof text - 1] = 0;
        va_end(args);
    }
}
