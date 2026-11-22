/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: a string's number, nonzero when the characters read as
 * one (FUN_00d9f310, its body not written) */
int FUN_00d9f310(const char *data, u64 length, float *number);

/* derived name: whether a value is a number or a string that reads as
 * one; the call timed */
// NONMATCHING: the base tests 4 then 3 and keeps case 3's block (`xor ecx, ecx; cmp eax, 3; jne; mov ecx,
// 1`, 0xdb71ba); the compile sets ecx to 1 before the tests (`mov ecx, 1; ...; cmp eax, 3; je`)
int FUN_00db70c0(lua_State *state, const HksObject *value)
{
    HksApiTimer timer(state);
    switch (value->type & 0xf) {
    case 3:
        return 1;
    case 4: {
        const HksString *string = static_cast<const HksString *>(value->value.pointer);
        float number;
        return FUN_00d9f310(string->data, string->lengthAndFlags & 0x3fffffffffffffff, &number) !=
               0;
    }
    }
    return 0;
}
