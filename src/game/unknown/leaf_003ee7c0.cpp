/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: looks the id at +0x24 of its object up in the list of ids
 * of the world its argument names (+0x10; the array at +0x5488, its count at
 * +0x5490): found, it sets the int at +0x614 of the target (+0x8 of the
 * argument) when bit 5 of the world's byte at +0x39d9 is set; not found, it
 * clears it. Returns 1 either way. */
struct IdList003ee7c0 { /* derived name */
    u32 *ids;           /* +0x0 */
    u32 count;          /* +0x8 */

    int indexOf(const u32 &id) const
    {
        for (int i = 0; i < count; i++) {
            if (ids[i] == id)
                return i;
        }
        return -1;
    }
};

struct World003ee7c0 { /* derived name */
    u8 unknown0[0x39d9];
    u8 flags39d9; /* +0x39d9: bit 5 */
    u8 unknown39da[0x1aae];
    IdList003ee7c0 ids; /* +0x5488 */
};

struct Target003ee7c0 { /* derived name */
    u8 unknown0[0x614];
    int unknown614; /* +0x614 */
};

struct Argument003ee7c0 { /* derived name */
    u8 unknown0[8];
    Target003ee7c0 *target; /* +0x8 */
    World003ee7c0 *world;   /* +0x10 */
};

struct Object003ee7c0 { /* derived name */
    u8 unknown0[0x24];
    u32 id; /* +0x24 */
};

int FUN_003ee7c0(const Object003ee7c0 *self, const Argument003ee7c0 *argument) /* derived name */
{
    World003ee7c0 *world = argument->world;
    Target003ee7c0 *target = argument->target;
    if (world->ids.indexOf(self->id) >= 0) {
        if (world->flags39d9 & 0x20)
            target->unknown614 = 1;
    } else {
        target->unknown614 = 0;
    }
    return 1;
}
