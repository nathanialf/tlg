/* src/sce/unknown/: functions of the Sony SDK objects linked at the head of the game region (0x1a3a70 to 0x1afa60, one CIE each in .eh_frame), built by the game compiler and outside the game module, matched before their library is known. */
#include "tlg_types.h"

bool FUN_001a6f10(unsigned value); /* derived name */

/* derived names: the bit offset of fragment `fragment` of the element at (x, y, z) of a
 * linear surface with `pitch` elements a row and `slicePitch` a slice, each fragment
 * `bitsPerFragment` bits, `fragments` of them (a power of two, at most 8), in bytes;
 * 0x80d30000 without an output or with a bad fragment count. */
// NONMATCHING: register assignment: the base keeps the fragment (r8d) in r15 and reads the fragment count from its stack slot again after the call (`mov edx, [rbp+0x20]`, an 8-byte frame); here the count stays in r14 across the call and r8 is spilled (a 0x18-byte frame); the arithmetic is the base's
int FUN_001ab020(u64 *out, u32 x, u32 y, u32 z, u32 fragment, u32 pitch, u32 slicePitch,
                 u32 bitsPerFragment, u32 fragments) /* derived name */
{
    int result = 0x80d30000;
    if (out && FUN_001a6f10(fragments) && fragments <= 8) {
        u32 element = y * pitch + x + z * slicePitch;
        *out =
            ((u64)(fragment * bitsPerFragment) + (u64)fragments * bitsPerFragment * element) >> 3;
        result = 0;
    }
    return result;
}
