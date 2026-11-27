/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include <algorithm>

/* derived name: a field of a word replaced by the value under its mask */
static inline u32 setField(u32 word, u32 value, int shift, u32 mask)
{
    return (word & ~(mask << shift)) | ((value & mask) << shift);
}

// NONMATCHING: registers and one constant's place: the base keeps the float's bits in
// edx and the exponent in esi (the build the other way: the same code otherwise, the
// parameters' order in the IR changes nothing), and materializes the exponent's 1
// before the bias is added (`mov esi, 1; sar; lea`, the build after the lea); 243
// bytes against 242
/* derived name: a float packed into a small float of the given widths
 * (the sign's, the exponent's and the mantissa's bits, the mantissa at bit
 * 0): without a sign bit a negative value packs as zero; zero and the
 * denormals keep exponent 0, an infinity or a NaN takes the exponent's
 * every bit; a value below the smallest exponent packs as exponent 1
 * without mantissa, one above the largest as the largest with every
 * mantissa bit */
u32 FUN_01329790(int signBits, int exponentBits, int mantissaBits, float value)
{
    if (!signBits)
        value = std::max(0.0f, value);

    union {
        float f;
        u32 u;
    } bits;

    bits.f = value;
    const int exponentMask = (1 << exponentBits) - 1;
    u32 mantissa = (bits.u & 0x7fffff) >> (23 - mantissaBits);
    const u32 sign = bits.u >> 31;
    const int biased = (bits.u >> 23) & 0xff;
    int exponent = 0;
    if (biased == 0) {
        exponent = 0;
    } else if (biased == 0xff) {
        exponent = exponentMask;
    } else {
        exponent = biased - 127 + (exponentMask >> 1);
        if (exponent <= 0) {
            exponent = 1;
            mantissa = 0;
        }
        if (exponent > exponentMask - 1) {
            exponent = exponentMask - 1;
            mantissa = 0x7fffff;
        }
    }
    u32 packed = mantissa & ((1 << mantissaBits) - 1);
    packed = setField(packed, exponent, mantissaBits, exponentMask);
    packed = setField(packed, sign, exponentBits + mantissaBits, (1 << signBits) - 1);
    return packed;
}
