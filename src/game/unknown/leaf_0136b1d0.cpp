/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_008f05f0 with the object, its first float, the x
 * and z of the vector its argument points to, and its second and third floats,
 * as a tail call; the pointer at 0x57adf70 holds it. The types are not traced.
 * Class and method unknown. */
struct Object0136b1d0; /* derived name */

struct Vector0136b1d0 { /* derived name */
    float x;
    float y;
    float z;
};

void FUN_008f05f0(Object0136b1d0 *self, float a, float x, float z, float b,
                  float c); /* derived name */

void FUN_0136b1d0(Object0136b1d0 *self, const Vector0136b1d0 *v, float a, float b,
                  float c) /* derived name */
{
    FUN_008f05f0(self, a, v->x, v->z, b, c);
}
