/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00de2e90 with the object and the character test
 * FUN_00de2e60 (an int to int function, as the class tests of the C library)
 * and returns 1; the pointer at 0x16bd008. Class and method unknown. */
struct Object00de1650; /* derived name */

int FUN_00de2e60(int c);                                   /* derived name */
void FUN_00de2e90(Object00de1650 *self, int (*test)(int)); /* derived name */

int FUN_00de1650(Object00de1650 *self) /* derived name */
{
    FUN_00de2e90(self, FUN_00de2e60);
    return 1;
}
