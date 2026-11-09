/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the exponent of its unsigned argument converted to
 * float (the float's bits shifted right by 23, less the bias 127): the index
 * of its highest set bit for a non-zero value; called by FUN_001a3c50 and
 * FUN_001a65c0. Class and method unknown. */
int FUN_001a6f30(unsigned value) /* derived name */
{
    union {
        float f;
        u32 bits;
    } converted;

    converted.f = (float)value;
    return (converted.bits >> 23) - 127;
}
