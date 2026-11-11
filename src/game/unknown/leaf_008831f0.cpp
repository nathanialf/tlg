/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: adds an int to the set of ints at +0x38 of the record that
 * the object at 0x57c9390 reaches through +0x108 and +0x30, unless it is there
 * already (FUN_004cd930 appends); the first argument is not read. The
 * fields' meaning is not traced. */
struct IntArray008831f0 /* derived name */
{
    int *data;      /* +0x0 */
    unsigned count; /* +0x8 */

    int indexOf(const int &value) const
    {
        for (int i = 0; i < count; i++)
            if (data[i] == value)
                return i;
        return -1;
    }
};

void FUN_004cd930(IntArray008831f0 *array, const int &value); /* derived name */

struct Record008831f0 /* derived name */
{
    u8 unknown0[0x38];
    IntArray008831f0 values; /* +0x38 */
};

struct Member057c9390_108 /* derived name */
{
    u8 unknown0[0x30];
    Record008831f0 *unknown30; /* +0x30 */
};

struct Object057c9390 /* derived name */
{
    u8 unknown0[0x108];
    Member057c9390_108 *unknown108; /* +0x108 */
};

extern Object057c9390 *D_57c9390;

struct Object008831f0; /* derived name */

// NONMATCHING: list-ilp order: the base loads the data pointer before the value (`mov rdx, [rdi];
// mov eax, [rsi]`), this the value first; with `value == data[i]` the loads come out in the base's
// order and the compare's operands the other way (`cmp eax, [rdx + rcx*4]`). The int index
// (widened, the compare truncated) is the base's.
void FUN_008831f0(Object008831f0 *, const int &value) /* derived name */
{
    IntArray008831f0 &values = D_57c9390->unknown108->unknown30->values;
    if (values.indexOf(value) < 0)
        FUN_004cd930(&values, value);
}
