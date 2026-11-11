/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"
#include "tlg_types.h"

/* derived names: two slots of the class whose vtable is at 0x16c05d8
 * (Object00ff18f0, config/vtables.derived.base.txt), slots 74 (0xff5e60, its
 * pointer at 0x16c0838) and 79 (0xff5ec0, at 0x16c0860). Each copies the
 * vector at +0x30 of its second argument into an aligned local, looks it up
 * through FUN_0134b990 in the field at +0x10 of its fourth and tests the
 * found record's float at +0x4 against 0 (at most 0; not below 0),
 * returning the test as an int. The object and the third argument are not
 * read; the types are not traced. */
struct Source00ff5e60 { /* derived name */
    u8 unknown0[0x30];
    Float4 unknown30; /* +0x30 */
};

struct Target00ff5e60 { /* derived name */
    u8 unknown0[0x10];
    u8 unknown10; /* type not traced; its address is passed */
};

struct Record0134b990 { /* derived name */
    u8 unknown0[4];
    float unknown4; /* +0x4 */
};

class Object00ff18f0; /* derived name */

const Record0134b990 *FUN_0134b990(void *field, const Float4A *point); /* derived name */

int FUN_00ff5e60(Object00ff18f0 *, const Source00ff5e60 *source, void *,
                 Target00ff5e60 *target) /* derived name */
{
    Float4A point(source->unknown30.x, source->unknown30.y, source->unknown30.z,
                  source->unknown30.w);
    return FUN_0134b990(&target->unknown10, &point)->unknown4 <= 0.0f;
}

int FUN_00ff5ec0(Object00ff18f0 *, const Source00ff5e60 *source, void *,
                 Target00ff5e60 *target) /* derived name */
{
    Float4A point(source->unknown30.x, source->unknown30.y, source->unknown30.z,
                  source->unknown30.w);
    return !(FUN_0134b990(&target->unknown10, &point)->unknown4 < 0.0f);
}
