/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_013bfd90 on the object with each pointer of the
 * array its argument describes (the unsigned count at +0x0, the pointers at
 * +0x8, indexed by the unsigned counter); slot 25 of the vtables at 0x16bba90
 * (its pointer at 0x16bbb68), 0x16bc170 (at 0x16bc248) and 0x16d2818 (at
 * 0x16d28f0), the family whose slot 32 is FUN_00dd2160. The pointers' target
 * is not traced. Class and method unknown. */
struct Object00dd1e40; /* derived name */
struct Target00dd1e40; /* derived name */

struct Argument00dd1e40 {   /* derived name */
    u32 count;              /* derived name */
    Target00dd1e40 **items; /* derived name */
};

void FUN_013bfd90(Object00dd1e40 *self, Target00dd1e40 *value); /* derived name */

// NONMATCHING: greedy's assignment: the array pointer in rax and the zero-extended
// index in rcx where the base has them the other way round (`mov rcx, [r15 + 8];
// mov eax, ebx`).
void FUN_00dd1e40(Object00dd1e40 *self, const Argument00dd1e40 *argument) /* derived name */
{
    for (u32 i = 0; i < argument->count; i++)
        FUN_013bfd90(self, argument->items[i]);
}
