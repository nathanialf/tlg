/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: called from FUN_01225ff0 at 0x1226de5 with a vector and two
 * floats, its int result kept. It calls FUN_01226f90 with the vector, the
 * function FUN_012274a0 (float (float, float, float), as FUN_01226f90 calls it
 * at 0x1227116 and compares the result with zero) and the two floats, as a
 * tail call; FUN_01226f80 passes FUN_01227330 instead. FUN_01226f90 reads the
 * floats at +0, +4 and +8 of the vector, writes +0xc, and returns -1, 0 or 1
 * (ebx at 0x1226fb6 and after). Owner and meaning unknown. */
struct Vector01226f90; /* derived name */

float FUN_012274a0(float, float, float); /* derived name */
int FUN_01226f90(Vector01226f90 *vector, float (*function)(float, float, float), float,
                 float); /* derived name */

int FUN_01227490(Vector01226f90 *vector, float a, float b) /* derived name */
{
    return FUN_01226f90(vector, FUN_012274a0, a, b);
}
