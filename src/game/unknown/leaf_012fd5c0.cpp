/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* the SDK objects' readers of the tile mode table (src/sce/unknown/leaf_001a72a0.cpp) */
int FUN_001a7090(u32 *out, u32 tileMode);
int FUN_001a70c0(u32 *out, u32 tileMode);
int FUN_001a70f0(u32 *out, u32 tileMode);
int FUN_001a72a0(u32 *out, u32 tileMode);
int FUN_001a71f0(u32 tileMode, u32 bitsPerElement, u32 fragments, u32 *out0, u32 *out2, u32 *out4,
                 u32 *out6);
int FUN_001a7360(u32 tileMode, u32 bitsPerElement, u32 fragments, u32 *out0, u32 *out8, u32 *out10,
                 u32 *out12);

/* derived names: the depth target's tile mode: set in bits 20 to 22 of the
 * depth and stencil words with FUN_001a70f0's field in bits 13 to 15; +0x2c
 * takes FUN_001a7090's field in bits 4 to 7, FUN_001a70c0's (FUN_001a72a0's
 * for the alternate swizzle; the old field when it fails) in 8 to 12 and 1 in
 * bit 0; for the fields 4 and 6 the four two-bit fields FUN_001a71f0
 * (FUN_001a7360) gives for the surface's bits per element and fragments go in
 * bits 13 to 20 (0 otherwise). */
void FUN_012fd5c0(DepthRenderTarget01499280 *target, u32 tileMode)
{
    u32 field8 = (target->word2c >> 8) & 0x1f;
    u32 field13;
    FUN_001a70f0(&field13, tileMode);
    target->word0 = (target->word0 & 0xff8f1fff) | (tileMode & 7) << 20 | (field13 & 7) << 13;
    target->word4 = (target->word4 & 0xff8f1fff) | (tileMode & 7) << 20 | (field13 & 7) << 13;
    u32 field4;
    FUN_001a7090(&field4, tileMode);
    if ((target->word2c & 0x1f00) == 0x1200) {
        FUN_001a72a0(&field8, tileMode);
    } else {
        FUN_001a70c0(&field8, tileMode);
    }
    target->word2c = (target->word2c & 0xffffe000) | (field4 & 0xf) << 4 | (field8 & 0x1f) << 8 | 1;
    u32 bits0 = 0;
    u32 bits2 = 0;
    u32 bits4 = 0;
    u32 bits6 = 0;
    if (field4 == 4 || field4 == 6) {
        u32 bitsPerElement;
        if (target->word0 & 3) {
            bitsPerElement = D_15253d0[D_15574b0[target->word0 & 3] & 0xff];
        } else if (target->word4 & 1) {
            bitsPerElement = D_15253d0[target->word4 & 1];
        } else {
            bitsPerElement = 8;
        }
        u32 fragments = 1u << ((target->word0 >> 2) & 3);
        if ((target->word2c & 0x1f00) == 0x1200) {
            FUN_001a7360(tileMode, bitsPerElement, fragments, &bits0, &bits2, &bits4, &bits6);
        } else {
            FUN_001a71f0(tileMode, bitsPerElement, fragments, &bits0, &bits2, &bits4, &bits6);
        }
    }
    target->word2c = (target->word2c & 0xffe01fff) | (bits0 & 3) << 13 | (bits2 & 3) << 15 |
                     (bits4 & 3) << 17 | (bits6 & 3) << 19;
}
