/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"

/* derived names: FUN_0136ad80 constructs a record that FUN_00754a90,
 * FUN_00756f50 and the other functions from 0x776bd0 to 0x79b9f0 build: the
 * array of 32-bit values at +0x58 (with its lock) constructed first, then
 * the fields from +0x0 set in the body (1 at +0x4, 1.0 at +0x1c, -180 and
 * 180 at +0x24 and +0x28) and the array emptied with room for 64 values
 * (tlg_game_array.h's clear(size): no count stored after the
 * reallocation). The bytes from +0x30 are not set here; what the fields
 * hold is not traced. */
struct Record0136ad80 { /* derived name */
    Record0136ad80();

    int unknown0;              /* +0x0 */
    int unknown4;              /* +0x4 */
    void *unknown8;            /* +0x8 */
    void *unknown10;           /* +0x10 */
    int unknown18;             /* +0x18 */
    float unknown1c;           /* +0x1c */
    int unknown20;             /* +0x20 */
    float lower;               /* +0x24: derived name */
    float upper;               /* +0x28: derived name */
    int unknown2c;             /* +0x2c */
    u8 unknown30[0x28];        /* not traced */
    Array01343a80<u32> values; /* +0x58 */
};

Record0136ad80::Record0136ad80()
{
    unknown0 = 0;
    unknown4 = 1;
    unknown8 = 0;
    unknown10 = 0;
    unknown18 = 0;
    unknown1c = 1.0f;
    unknown20 = 0;
    lower = -180.0f;
    upper = 180.0f;
    unknown2c = 0;
    values.clear(64);
}
