/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_format_table.h"

/* derived names: FUN_001a3c50 checks its three arguments (0x80d30000 for one
 * out of range or no output) and stores a number below 16; these four read
 * two-bit fields of the word that number selects in the table at 0x14d2ee0,
 * which no other function reads, and return FUN_001a3c50's status. */
static const FieldWord001a7180 D_14d2ee0[16] = {
#include "gen/D_14d2ee0.inc"
};

int FUN_001a3c50(u32 *out, u32 a, u32 b, u32 c); /* derived name */

/* stores bits 6 and 7 of the word */
int FUN_001a7180(u32 *out, u32 a, u32 b, u32 c) /* derived name */
{
    if (!out) {
        return 0x80d30000;
    }
    u32 index;
    int status = FUN_001a3c50(&index, a, b, c);
    if (status == 0) {
        *out = (D_14d2ee0[index].bits >> 6) & 0x3;
    }
    return status;
}

/* stores bits 0 and 1, 2 and 3, 4 and 5, 6 and 7 of the word, each where an output is given */
int FUN_001a71f0(u32 a, u32 b, u32 c, u32 *out0, u32 *out2, u32 *out4, u32 *out6) /* derived name */
{
    u32 index;
    int status = FUN_001a3c50(&index, a, b, c);
    if (status == 0) {
        u32 bits = D_14d2ee0[index].bits;
        if (out0) {
            *out0 = bits & 0x3;
        }
        if (out2) {
            *out2 = (bits >> 2) & 0x3;
        }
        if (out4) {
            *out4 = (bits >> 4) & 0x3;
        }
        if (out6) {
            *out6 = (bits >> 6) & 0x3;
        }
    }
    return status;
}

/* stores bits 12 and 13 of the word */
int FUN_001a72f0(u32 *out, u32 a, u32 b, u32 c) /* derived name */
{
    if (!out) {
        return 0x80d30000;
    }
    u32 index;
    int status = FUN_001a3c50(&index, a, b, c);
    if (status == 0) {
        *out = (D_14d2ee0[index].bits >> 12) & 0x3;
    }
    return status;
}

/* stores bits 0 and 1, 8 and 9, 10 and 11, 12 and 13 of the word, each where an output is given */
int FUN_001a7360(u32 a, u32 b, u32 c, u32 *out0, u32 *out8, u32 *out10,
                 u32 *out12) /* derived name */
{
    u32 index;
    int status = FUN_001a3c50(&index, a, b, c);
    if (status == 0) {
        u32 bits = D_14d2ee0[index].bits;
        if (out0) {
            *out0 = bits & 0x3;
        }
        if (out8) {
            *out8 = (bits >> 8) & 0x3;
        }
        if (out10) {
            *out10 = (bits >> 10) & 0x3;
        }
        if (out12) {
            *out12 = (bits >> 12) & 0x3;
        }
    }
    return status;
}
