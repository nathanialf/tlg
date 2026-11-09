/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: called from FUN_00f6d880 at 0xf6e33c with a vector and two
 * floats, its int result kept. It calls FUN_00f6e820 with the vector, the
 * function FUN_00f6ebc0 (float (float, float, float), as FUN_00f6e820 calls it
 * at 0xf6e9a6 and compares the result with zero) and the two floats, as a tail
 * call; FUN_00f6ed20 passes FUN_00f6ed30 instead. FUN_00f6e820 reads the
 * floats at +0, +4 and +8 of the vector, writes +0xc, and returns -1, 0 or 1
 * (ebx at 0xf6e846 and after). Owner and meaning unknown. */
struct Vector00f6e820; /* derived name */

float FUN_00f6ebc0(float, float, float); /* derived name */
int FUN_00f6e820(Vector00f6e820 *vector, float (*function)(float, float, float), float,
                 float); /* derived name */

int FUN_00f6e810(Vector00f6e820 *vector, float a, float b) /* derived name */
{
    return FUN_00f6e820(vector, FUN_00f6ebc0, a, b);
}
