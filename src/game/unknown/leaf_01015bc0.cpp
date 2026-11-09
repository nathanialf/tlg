/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: called from FUN_0100e910 at 0x101029f with a vector and two
 * floats, its int result kept. It calls FUN_01015bd0 with the vector, the
 * function FUN_01015f70 (float (float, float, float), as FUN_01015bd0 calls it
 * at 0x1015d56 and compares the result with zero) and the two floats, as a
 * tail call; FUN_010160d0 passes FUN_010160e0 instead. FUN_01015bd0 reads the
 * floats at +0, +4 and +8 of the vector, writes +0xc, and returns -1, 0 or 1
 * (ebx at 0x1015bf6 and after). Owner and meaning unknown. */
struct Vector01015bd0; /* derived name */

float FUN_01015f70(float, float, float); /* derived name */
int FUN_01015bd0(Vector01015bd0 *vector, float (*function)(float, float, float), float,
                 float); /* derived name */

int FUN_01015bc0(Vector01015bd0 *vector, float a, float b) /* derived name */
{
    return FUN_01015bd0(vector, FUN_01015f70, a, b);
}
