/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: called from FUN_00fbb8e0 at 0xfbc6d5 with a vector and two
 * floats, its int result kept. It calls FUN_00fbd4e0 with the vector, the
 * function FUN_00fbd9f0 (float (float, float, float), as FUN_00fbd4e0 calls it
 * at 0xfbd666 and compares the result with zero) and the two floats, as a tail
 * call; FUN_00fbd4d0 passes FUN_00fbd880 instead. FUN_00fbd4e0 reads the
 * floats at +0, +4 and +8 of the vector, writes +0xc, and returns -1, 0 or 1
 * (ebx at 0xfbd506 and after). Owner and meaning unknown. */
struct Vector00fbd4e0; /* derived name */

float FUN_00fbd9f0(float, float, float); /* derived name */
int FUN_00fbd4e0(Vector00fbd4e0 *vector, float (*function)(float, float, float), float,
                 float); /* derived name */

int FUN_00fbd9e0(Vector00fbd4e0 *vector, float a, float b) /* derived name */
{
    return FUN_00fbd4e0(vector, FUN_00fbd9f0, a, b);
}
