/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback whose address the function before it (ending at
 * 0x82ee88) stores with a context pointer into an array of 16-byte entries
 * (callback, context). Dispatches on the state at +0x24 (a four-case jump
 * table, 0x15587a4): 0 gives 1; 1 and any other value give 0; 2 calls
 * FUN_0082e290 on the object with 0 and 1 and gives 0; 3 gives whether the
 * int at +0xd0 is zero. Class and method unknown. */
struct Object0082ee90 /* derived name */
{
    u8 unknown0[0x24];
    unsigned state; /* +0x24 */ /* derived name */
    u8 unknown28[0xa8];
    int unknownD0; /* +0xd0 */
};

void FUN_0082e290(Object0082ee90 *self, int a, int b); /* derived name */

// NONMATCHING: block placement: the build lays the shared return after the default block
// (and its copy at the end), the base after case 3 with the default jumping to it: the switch
// weights' class (r246104 to r246522, held; NOTES round 219C)
int FUN_0082ee90(Object0082ee90 *self) /* derived name */
{
    switch (self->state) {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        FUN_0082e290(self, 0, 1);
        return 0;
    case 3:
        return self->unknownD0 == 0;
    default:
        return 0;
    }
}
