/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: called from FUN_00f3c260 at 0xf3d473 with a 16-byte vector
 * copied to the stack and two floats. It calls FUN_00f54500 with the vector,
 * the function FUN_00f54a10 (float (float, float, float), as FUN_00f54500
 * calls it at 0xf54686 and tests the result) and the two floats, as a tail
 * call. FUN_00f54500 reads the floats at +0, +4 and +8 of the vector; its
 * return type is not traced. Owner and meaning unknown. */
struct Vector00f54500; /* derived name */

float FUN_00f54a10(float, float, float); /* derived name */
void FUN_00f54500(Vector00f54500 *vector, float (*function)(float, float, float), float,
                  float); /* derived name */

void FUN_00f54a00(Vector00f54500 *vector, float a, float b) /* derived name */
{
    FUN_00f54500(vector, FUN_00f54a10, a, b);
}
