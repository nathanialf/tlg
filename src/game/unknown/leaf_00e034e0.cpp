/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: pushes the int at +0x40 of the argument (0 when its
 * pointer at +0x60 is null) on the object's stack of 16 ints at +0xf0, the
 * index of its top value at +0x130; a full stack is left as it is. Returns
 * 0. The index is incremented first and then used (`mov rdx, rax; inc rdx`
 * in 64 bits with the store at +0xf4 + 4 * the old index: the code
 * generator's promotion of the sign extension through the increment). The
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
    u8 unknown0[0xf0];
    int values[16]; /* +0xf0 */
    int top;        /* +0x130: the index of the top value */

    void push(int value)
    {
        if (top < 15)
            values[++top] = value;
    }
};

int FUN_00e034e0(Object00e034e0 *self, Argument00e034e0 *argument) /* derived name */
{
    if (argument->unknown60)
        self->push(argument->unknown40);
    else
        self->push(0);
    return 0;
}
