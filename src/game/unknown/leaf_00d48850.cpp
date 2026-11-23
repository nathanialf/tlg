/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: no direct caller; its first argument is not read. Each of
 * the five parts the second argument holds at +0x240 has bit 2 of its flags
 * at +0x5c set, and the object takes the value at +0x48 of the last part
 * present into +0x268. */
struct Part00d48850 { /* derived name */
    u8 unknown0[0x48];
    int unknown48; /* +0x48 */
    u8 unknown4c[0x10];
    u32 flags; /* +0x5c */
};

struct Object00d48850 { /* derived name */
    u8 unknown0[0x240];
    Part00d48850 *parts[5]; /* +0x240 */
    int unknown268;         /* +0x268 */
};

void FUN_00d48850(void *, Object00d48850 *object) /* derived name */
{
    for (int i = 0; i < 5; ++i) {
        if (object->parts[i]) {
            object->parts[i]->flags |= 4;
            object->unknown268 = object->parts[i]->unknown48;
        }
    }
}
