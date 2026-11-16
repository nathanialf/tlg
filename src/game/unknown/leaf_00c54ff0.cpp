/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 15 of the vtable at 0x16b8560 (its pointer at
 * 0x16b85d8, the class Object016b8560 of config/vtables.derived.base.txt):
 * copies one object's flags at +0x24 to another, bit 0
 * cleared, after FUN_00c55060 has run on the target; the int at +0x21c is
 * then bit 9 of the flags cleared when bits 9 or 10 are set, else, with an
 * owner at +0x38, whether the target's int at +0x218 equals the owner's at
 * +0x220, or the owner's own +0x21c when that is -1. The object is not
 * traced further. Class and method unknown. */
struct Object00c54ff0 { /* derived name */
    u8 unknown0[0x24];
    u32 flags; /* +0x24, derived name */
    u8 unknown28[0x10];
    Object00c54ff0 *owner; /* +0x38, derived name */
    u8 unknown40[0x1d8];
    int unknown218; /* +0x218 */
    int unknown21c; /* +0x21c */
    int unknown220; /* +0x220 */
};

void FUN_00c55060(Object00c54ff0 *object); /* derived name */

void FUN_00c54ff0(void *, const Object00c54ff0 *source, Object00c54ff0 *target) /* derived name */
{
    FUN_00c55060(target);
    u32 flags = source->flags;
    target->flags = flags & ~1u;
    if (flags & 0x600) {
        target->unknown21c = !(flags & 0x200);
    } else if (Object00c54ff0 *owner = target->owner) {
        if (owner->unknown220 != -1)
            target->unknown21c = target->unknown218 == owner->unknown220;
        else
            target->unknown21c = owner->unknown21c;
    }
}
