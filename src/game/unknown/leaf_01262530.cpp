/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"
#include "tlg_types.h"

/* derived names: two slots of the class whose vtable is at 0x16c2780
 * (Object0125dfc0, config/vtables.derived.base.txt), slots 65 (0x1262530, its
 * pointer at 0x16c2998) and 70 (0x1262590, at 0x16c29c0), the same bodies as
 * Object00ff18f0's slots FUN_00ff5e60 and FUN_00ff5ec0: each copies the
 * vector at +0x30 of its second argument into an aligned local, looks it up
 * through FUN_0134b990 in the field at +0x10 of its fourth and tests the found
 * record's float at +0x4 against 0 (at most 0; not below 0), returning the
 * test as an int. The object and the third argument are not read; the types
 * are not traced. */
struct Source01262530 { /* derived name */
    u8 unknown0[0x30];
    Float4 unknown30; /* +0x30 */
};

struct Target01262530 { /* derived name */
    u8 unknown0[0x10];
    u8 unknown10; /* type not traced; its address is passed */
};

struct Record0134b990 { /* derived name */
    u8 unknown0[4];
    float unknown4; /* +0x4 */
};

class Object0125dfc0; /* derived name */

const Record0134b990 *FUN_0134b990(void *field, const Float4A *point); /* derived name */

int FUN_01262530(Object0125dfc0 *, const Source01262530 *source, void *,
                 Target01262530 *target) /* derived name */
{
    Float4A point(source->unknown30.x, source->unknown30.y, source->unknown30.z,
                  source->unknown30.w);
    return FUN_0134b990(&target->unknown10, &point)->unknown4 <= 0.0f;
}

int FUN_01262590(Object0125dfc0 *, const Source01262530 *source, void *,
                 Target01262530 *target) /* derived name */
{
    Float4A point(source->unknown30.x, source->unknown30.y, source->unknown30.z,
                  source->unknown30.w);
    return !(FUN_0134b990(&target->unknown10, &point)->unknown4 < 0.0f);
}
