/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_013bf850 on the object with each pointer of the
 * array its argument describes (the unsigned count at +0x0, the pointers at
 * +0x8, indexed by the unsigned counter); slot 37 of the vtables at 0x16bba90
 * (its pointer at 0x16bbbc8), 0x16bc170 (at 0x16bc2a8) and 0x16d2818 (at
 * 0x16d2950), the family whose slot 32 is FUN_00dd2160. The pointers' target
 * is not traced. Class and method unknown. */
struct Object00dd24b0; /* derived name */
struct Target00dd24b0; /* derived name */

struct Argument00dd24b0 {   /* derived name */
    u32 count;              /* derived name */
    Target00dd24b0 **items; /* derived name */
};

void FUN_013bf850(Object00dd24b0 *self, Target00dd24b0 *value); /* derived name */

// NONMATCHING: greedy's assignment: the array pointer in rax and the zero-extended
// index in rcx where the base has them the other way round (`mov rcx, [r15 + 8];
// mov eax, ebx`).
void FUN_00dd24b0(Object00dd24b0 *self, const Argument00dd24b0 *argument) /* derived name */
{
    for (u32 i = 0; i < argument->count; i++)
        FUN_013bf850(self, argument->items[i]);
}
