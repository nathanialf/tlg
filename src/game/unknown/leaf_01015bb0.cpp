/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: called from FUN_01011560 at 0x1013a53 with a vector and a
 * float, its int result kept. It calls FUN_01015bd0 with the vector, the
 * function FUN_01016220 (float (float, float, float)), the float and 0.0f, as
 * a tail call, as FUN_010160d0 does with FUN_010160e0 and two floats. Class
 * and method unknown. */
struct Vector01015bd0; /* derived name */

float FUN_01016220(float, float, float); /* derived name */
int FUN_01015bd0(Vector01015bd0 *vector, float (*function)(float, float, float), float,
                 float); /* derived name */

int FUN_01015bb0(Vector01015bd0 *vector, float a) /* derived name */
{
    return FUN_01015bd0(vector, FUN_01016220, a, 0.0f);
}
