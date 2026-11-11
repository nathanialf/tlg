/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include <algorithm>

/* derived names: slot 1 of the vtable at 0x16d2d98 (slot 0 is the library's
 * 0x1af750; no constructor stores it): clamps the count at +0x30 of its
 * second argument to 1 to 4, a count that is not positive becoming 1 (the
 * upper bound through std::min, whose reference result is the select of the
 * two addresses). The object itself is not read. */
struct Record013c99b0 { /* derived name */
    u8 unknown0[0x30];
    s32 count; /* +0x30 */
};

class Object013c99b0; /* derived name */

// NONMATCHING: the base keeps the bound on the stack and loads through the
// select of the two addresses (`cmovl rdi, rsi; mov edx, [rdi]`); here SROA
// speculates the select's loads (isSafeSelectToSpeculate: std::min's own
// reload of the count in the select's block proves the field safe) and the
// local is gone, no canary. The base's form of the clamp is not found.
void FUN_013c99b0(Object013c99b0 *, Record013c99b0 *record) /* derived name */
{
    const int maxCount = 4;
    record->count = record->count > 0 ? std::min(record->count, maxCount) : 1;
}
