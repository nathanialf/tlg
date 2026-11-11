/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"
#include "tlg_types.h"

/* derived names: two slots of the class whose vtable is at 0x16c05d8
 * (Object00ff18f0, config/vtables.derived.base.txt), slot 104 (0xffe820) and
 * the one after it (0xffe870). Each builds a key on the stack from its third
 * argument (the int at +0x58 and one of its two aligned vectors, +0x70 or
 * +0x60) and hands the second argument and the key's address to FUN_00f52000
 * or FUN_00f51f20; the object itself is not read. The fields are not traced
 * further; the key's layout is the stores' (an int at +0, a vector at +0x10). */
struct Object00ffe820Source { /* derived name */
    u8 unknown0[0x58];
    s32 unknown58; /* +0x58 */
    u8 unknown5c[4];
    Float4A unknown60; /* +0x60 */
    Float4A unknown70; /* +0x70 */
};

struct Object00f52000Key { /* derived name */
    s32 unknown0;          /* +0x0 */
    Float4A unknown10;     /* +0x10 */
};

class Object00ff18f0; /* derived name */

void FUN_00f52000(void *target, const Object00f52000Key *key); /* derived name */
void FUN_00f51f20(void *target, const Object00f52000Key *key); /* derived name */

void FUN_00ffe820(Object00ff18f0 *, void *target,
                  const Object00ffe820Source *source) /* derived name */
{
    Object00f52000Key key;
    key.unknown0 = source->unknown58;
    key.unknown10 = source->unknown70;
    FUN_00f52000(target, &key);
}

void FUN_00ffe870(Object00ff18f0 *, void *target,
                  const Object00ffe820Source *source) /* derived name */
{
    Object00f52000Key key;
    key.unknown0 = source->unknown58;
    key.unknown10 = source->unknown60;
    FUN_00f51f20(target, &key);
}
