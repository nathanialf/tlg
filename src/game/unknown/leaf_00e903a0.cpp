/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_math.h"
#include "tlg_simd.h"

/* derived names: slot 13 of the vtable at 0x16be190: fills the record its
 * argument points to with its defaults: the vectors (0, 0, 1, 0) and (0, 1, 0,
 * 0) as floats, the vector (0, -9.81, 0, 1) (a gravity, stored first), then a
 * zero int and two zero floats (the int is not merged with them; the base
 * stores 4 bytes at +0x30 and 8 at +0x34). Class and method unknown. */
struct Defaults00e903a0 { /* derived name */
    Float4A unknown0;
    Float4A unknown10;
    Vec4 unknown20;
    int unknown30;
    float unknown34;
    float unknown38;
};

struct Object00e903a0; /* derived name */

void FUN_00e903a0(const Object00e903a0 *, Defaults00e903a0 *defaults) /* derived name */
{
    defaults->unknown20 = _mm_setr_ps(0.0f, -9.81f, 0.0f, 1.0f);
    defaults->unknown0.set(0.0f, 0.0f, 1.0f, 0.0f);
    defaults->unknown10.set(0.0f, 1.0f, 0.0f, 0.0f);
    defaults->unknown30 = 0;
    defaults->unknown34 = 0.0f;
    defaults->unknown38 = 0.0f;
}
