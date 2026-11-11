/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_format_table.h"

/* derived names: stores the top five bits (27 to 31) of the format word the
 * format number selects in the table at 0x14d2e60 and returns 0; returns
 * 0x80d30000 without an output or for a number past 31. Called by
 * FUN_001a44e0, FUN_001a5cb0, FUN_001ac870 and FUN_012fd5c0. The table's
 * other readers, FUN_001a7060 to FUN_001a7120, make the same test and store
 * another bit range each. */
static const FormatWord001a72a0 D_14d2e60[32] = {
#include "gen/D_14d2e60.inc"
};

/* stores the 3 bits 22 to 24 of the format word */
// NONMATCHING: list-ilp order, the bextr control constant (mov ecx, imm) is scheduled before the
// table's lea, the base has the lea first (rcx the table, edx the control)
int FUN_001a7060(u32 *out, u32 format) /* derived name */
{
    if (!out || format > 31) {
        return 0x80d30000;
    }
    *out = (D_14d2e60[format].bits >> 22) & 0x7;
    return 0;
}

/* stores the 4 bits 2 to 5 of the format word */
// NONMATCHING: list-ilp order, the bextr control constant (mov ecx, imm) is scheduled before the
// table's lea, the base has the lea first (rcx the table, edx the control)
int FUN_001a7090(u32 *out, u32 format) /* derived name */
{
    if (!out || format > 31) {
        return 0x80d30000;
    }
    *out = (D_14d2e60[format].bits >> 2) & 0xf;
    return 0;
}

/* stores the 5 bits 6 to 10 of the format word */
// NONMATCHING: list-ilp order, the bextr control constant (mov ecx, imm) is scheduled before the
// table's lea, the base has the lea first (rcx the table, edx the control)
int FUN_001a70c0(u32 *out, u32 format) /* derived name */
{
    if (!out || format > 31) {
        return 0x80d30000;
    }
    *out = (D_14d2e60[format].bits >> 6) & 0x1f;
    return 0;
}

/* stores the 3 bits 11 to 13 of the format word */
// NONMATCHING: list-ilp order, the bextr control constant (mov ecx, imm) is scheduled before the
// table's lea, the base has the lea first (rcx the table, edx the control)
int FUN_001a70f0(u32 *out, u32 format) /* derived name */
{
    if (!out || format > 31) {
        return 0x80d30000;
    }
    *out = (D_14d2e60[format].bits >> 11) & 0x7;
    return 0;
}

/* stores the 2 bits 25 to 26 of the format word */
// NONMATCHING: list-ilp order, the bextr control constant (mov ecx, imm) is scheduled before the
// table's lea, the base has the lea first (rcx the table, edx the control)
int FUN_001a7120(u32 *out, u32 format) /* derived name */
{
    if (!out || format > 31) {
        return 0x80d30000;
    }
    *out = (D_14d2e60[format].bits >> 25) & 0x3;
    return 0;
}

int FUN_001a72a0(u32 *out, u32 format) /* derived name */
{
    if (!out || format > 31) {
        return 0x80d30000;
    }
    *out = D_14d2e60[format].bits >> 27;
    return 0;
}
