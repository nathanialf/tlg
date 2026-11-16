/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: 21 keys of 32 bytes, each a state byte (0 empty, 2 filled
 * from a neighbour) and a value at +0x14. An empty key takes the value of
 * the nearest set key before it, then, in a pass from the end, of the
 * nearest key after it; the keys a pass filled count as set for the next
 * pass. One other unit holds a copy of these bytes (0x11b8890), called only
 * from its own unit. */
struct Key010a0730 { /* derived name */
    u8 state;        /* +0x0 */
    u8 unknown1[0x13];
    float value; /* +0x14 */
    u8 unknown18[0x8];
};

void FUN_010a0730(Key010a0730 *keys) /* derived name */
{
    float last = 0.0f;
    int found = 0;
    for (int i = 0; i < 21; ++i) {
        if (keys[i].state != 0) {
            last = keys[i].value;
            found = 1;
        } else if (found) {
            keys[i].state = 2;
            keys[i].value = last;
        }
    }
    last = 0.0f;
    found = 0;
    for (int i = 20; i >= 0; --i) {
        if (keys[i].state != 0) {
            last = keys[i].value;
            found = 1;
        } else if (found) {
            keys[i].state = 2;
            keys[i].value = last;
        }
    }
}
