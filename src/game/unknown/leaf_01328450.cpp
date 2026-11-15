/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: its pointer at 0x16c5520 is in the table of function pointers
 * at 0x16c5500 (leaf_01328770.cpp's): converts the four unsigned
 * values its second argument points to, each in double times the matching one
 * of the four doubles at +0x28 of its third argument, to four floats at its
 * first. The record's type is not
 * traced. */
struct Scale01328450 { /* derived name */
    u8 unknown0[0x28];
    double unknown28[4];
};

// NONMATCHING: the instructions are the base's; the layout does not place the 32-byte constant
// of the multiply (65536.0 four times, the relocation at +0x19: "literal b'\x00' of .rodata") and
// refuses the row: a tool question.
/* The four are converted before the first is stored (the base converts them as
 * one vector: the unsigned conversion to double is the back end's, the high
 * half times 65536 plus the low half). */
void FUN_01328450(float *destination, const u32 *source,
                  const Scale01328450 *scale) /* derived name */
{
    float x = (float)(source[0] * scale->unknown28[0]);
    float y = (float)(source[1] * scale->unknown28[1]);
    float z = (float)(source[2] * scale->unknown28[2]);
    float w = (float)(source[3] * scale->unknown28[3]);
    destination[0] = x;
    destination[1] = y;
    destination[2] = z;
    destination[3] = w;
}
