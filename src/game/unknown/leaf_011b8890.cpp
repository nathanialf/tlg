/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a copy of FUN_010a0730 (leaf_010a0730.cpp, where it is
 * described): an empty key of 21 takes the value of the nearest set key
 * before it, then of the nearest after it. Called only from its own unit. */
struct Key011b8890 { /* derived name */
    u8 state;        /* +0x0 */
    u8 unknown1[0x13];
    float value; /* +0x14 */
    u8 unknown18[0x8];
};

void FUN_011b8890(Key011b8890 *keys) /* derived name */
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
