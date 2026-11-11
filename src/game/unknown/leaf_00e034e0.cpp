/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: appends the int at +0x40 of the argument (0 when its
 * pointer at +0x60 is null) to the object's list of at most 15 ints at +0xf4,
 * its count at +0x130; a full list is left as it is. Returns 0. The
 * fields' meaning is not traced. */
struct Argument00e034e0 /* derived name */
{
    u8 unknown0[0x40];
    int unknown40; /* +0x40 */
    u8 unknown44[0x1c];
    void *unknown60; /* +0x60 */
};

struct Object00e034e0 /* derived name */
{
    u8 unknown0[0xf4];
    int values[15]; /* +0xf4 */
    int count;      /* +0x130 */

    void push(int value)
    {
        if (count < 15)
            values[count++] = value;
    }
};

// NONMATCHING: the base increments the sign-extended count in 64 bits (`mov rdx, rax; inc rdx`,
// `lea rcx, [rax + 1]`) and stores its low half; this increments in 32 bits (`mov edx, eax; inc
// edx`, `lea ecx, [rax + 1]`): the add narrowed through the truncation here; otherwise equal
int FUN_00e034e0(Object00e034e0 *self, Argument00e034e0 *argument) /* derived name */
{
    if (argument->unknown60)
        self->push(argument->unknown40);
    else
        self->push(0);
    return 0;
}
