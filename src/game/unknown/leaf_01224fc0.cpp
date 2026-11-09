/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: slot 4 of the vtable at 0x16c2168 (its pointer at 0x16c2198),
 * one of the four vtables 0x16c2118, 0x16c2168, 0x16c21b8 and 0x16c2208 stored
 * by FUN_0121a680, whose slot 4 holds FUN_01224fb0 to FUN_01224fe0. It calls
 * FUN_012231b0 with the object, 0 and 6 as a tail call (its siblings pass 5,
 * 17, 18). FUN_012231b0, the same 0x1e00-byte body as FUN_00f67000, keeps the
 * second as a 32-bit value (movl to -0x3f8(%rbp)) and the third as a 64-bit
 * one (movq to -0x340(%rbp) at 0x12231ce); their meaning and the return type
 * are not traced. Class and method unknown. */
#include "tlg_types.h"

struct Object012231b0; /* derived name */

void FUN_012231b0(Object012231b0 *self, int, u64); /* derived name */

void FUN_01224fc0(Object012231b0 *self) /* derived name */
{
    FUN_012231b0(self, 0, 6);
}
