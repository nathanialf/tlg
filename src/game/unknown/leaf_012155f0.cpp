/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: called from FUN_01213ab0 at 0x1213f87 with a vector and two
 * floats, its int result kept. It calls FUN_012150f0 with the vector, the
 * function FUN_01215600 (float (float, float, float), as FUN_012150f0 calls it
 * at 0x1215276 and compares the result with zero) and the two floats, as a
 * tail call; FUN_012150e0 passes FUN_01215490 instead. FUN_012150f0 reads the
 * floats at +0, +4 and +8 of the vector, writes +0xc, and returns -1, 0 or 1
 * (ebx at 0x1215116 and after). Owner and meaning unknown. */
struct Vector012150f0; /* derived name */

float FUN_01215600(float, float, float); /* derived name */
int FUN_012150f0(Vector012150f0 *vector, float (*function)(float, float, float), float,
                 float); /* derived name */

int FUN_012155f0(Vector012150f0 *vector, float a, float b) /* derived name */
{
    return FUN_012150f0(vector, FUN_01215600, a, b);
}
