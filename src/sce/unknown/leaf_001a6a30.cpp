/* src/sce/unknown/: functions of the Sony SDK objects linked at the head of the game region (0x1a3a70 to 0x1afa60, one CIE each in .eh_frame), built by the game compiler and outside the game module, matched before their library is known. */
#include "tlg_types.h"

/* derived names: a three- or four-bit code from two values: bit 0 the
 * parity of the first value's bits 0 and 1 and the second's bit 0, bits 1 and
 * 2 the two values' bits 1 and 2 combined, and with a size of 16 bit 3 the
 * first value's bit 3 against the second's bit 2. The values are not traced. */
u32 FUN_001a6a30(u32 first, u32 second, int size) /* derived name */
{
    const u32 difference = second ^ first;
    u32 code = (((first >> 1) ^ difference) & 1) | (difference & 6);
    if (size == 16) {
        code |= (first ^ (second << 1)) & 8;
    }
    return code;
}
