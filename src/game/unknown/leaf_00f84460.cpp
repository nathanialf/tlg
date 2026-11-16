/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot of the vtable at 0x16bfd30 (its pointer there): two
 * requests handed to FUN_00f83ae0, one per channel of the owner: three ids
 * (8, 11, 7 for the first, 14, 17, 13 for the second) and the channel's
 * value. The classes are not traced. */
struct Request00f83ae0 { /* derived name */
    int unknown0;
    int unknown4;
    int unknown8;
    int unknownc;
};

/* derived name: two of them at +0x548 of the owner, 0xe0 bytes apart */
struct Channel00f84460 { /* derived name */
    int value;
    u8 unknown4[0xdc];
};

struct Owner00f84460 { /* derived name */
    u8 unknown0[0x548];
    Channel00f84460 channels[2]; /* +0x548 */
};

struct Object00f84460 { /* derived name */
    u8 unknown0[0x8];
    Owner00f84460 *owner; /* +0x8 */
};

void FUN_00f83ae0(Object00f84460 *self, const Request00f83ae0 *request); /* derived name */

/* derived name: one request for a channel handed on */
inline void requestChannel(Object00f84460 *self, int a, int b, int c, int channel)
{
    const Request00f83ae0 request = {a, b, c, self->owner->channels[channel].value};
    FUN_00f83ae0(self, &request);
}

void FUN_00f84460(Object00f84460 *self) /* derived name */
{
    requestChannel(self, 8, 11, 7, 0);
    requestChannel(self, 14, 17, 13, 1);
}
