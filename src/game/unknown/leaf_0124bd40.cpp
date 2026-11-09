/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: called from FUN_01249f10 at 0x124ad05 with a vector and two
 * floats, its int result kept. It calls FUN_0124b840 with the vector, the
 * function FUN_0124bd50 (float (float, float, float), as FUN_0124b840 calls it
 * at 0x124b9c6 and compares the result with zero) and the two floats, as a
 * tail call; FUN_0124b830 passes FUN_0124bbe0 instead. FUN_0124b840 reads the
 * floats at +0, +4 and +8 of the vector, writes +0xc, and returns -1, 0 or 1
 * (ebx at 0x124b866 and after). Owner and meaning unknown. */
struct Vector0124b840; /* derived name */

float FUN_0124bd50(float, float, float); /* derived name */
int FUN_0124b840(Vector0124b840 *vector, float (*function)(float, float, float), float,
                 float); /* derived name */

int FUN_0124bd40(Vector0124b840 *vector, float a, float b) /* derived name */
{
    return FUN_0124b840(vector, FUN_0124bd50, a, b);
}
