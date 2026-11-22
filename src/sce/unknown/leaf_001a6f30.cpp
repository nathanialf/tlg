/* src/sce/unknown/: functions of the Sony SDK objects linked at the head of the game region (0x1a3a70 to 0x1afa60, one CIE each in .eh_frame), built by the game compiler and outside the game module, matched before their library is known. */
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
