/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: a string's number, nonzero when the characters read as
 * one (FUN_00d9f310, its body not written) */
int FUN_00d9f310(const char *data, u64 length, float *number);

/* derived name: a value's number written to `number`, a string's read as
 * one; false for any other value */
inline bool toNumber(const HksObject *value, float *number)
{
    const int type = value->type & 0xf;
    if (type == 4) {
        const HksString *string = static_cast<const HksString *>(value->value.pointer);
        return FUN_00d9f310(string->data, string->lengthAndFlags & 0x3fffffffffffffff, number);
    }
    if (type == 3) {
        *number = value->value.number;
        return true;
    }
    return false;
}

/* derived name: the number a value holds, a string's read as a number, 0
 * for any other value; the call timed */
// NONMATCHING: the base joins the three numbers as integers (the string's at [rbp-0x34], 0, the value's
// [rsi+8], `vmovd xmm0, eax` after the merge) and skips the mark's test only for a value of no number;
// this form keeps a float store to the local (0xdb703c)
float FUN_00db6f40(lua_State *state, const HksObject *value)
{
    HksApiTimer timer(state);
    float number;
    if (toNumber(value, &number))
        return number;
    return 0;
}
