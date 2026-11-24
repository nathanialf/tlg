/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: the object at +0x1a0 of the record at +0x40 of the object
 * the pointer at 0x57c9390 holds (leaf_00645980.cpp's): a Name at +0x68,
 * the one-bit flag 1 of its byte at +0x2441 (`test byte, 2`) */
struct Member057c9390_40_1a0 { /* derived name */
    u8 unknown0[0x68];
    Name unknown68; /* +0x68 */
    u8 unknown6c[0x23d5];
    bool unknown2441_0 : 1;
    bool unknown2441_1 : 1;
};

/* derived names: the record at +0x40: the object at +0x1a0 and two
 * pointers at +0x1f0 and +0x230 compared */
struct Member057c9390_40 { /* derived name */
    u8 unknown0[0x1a0];
    Member057c9390_40_1a0 *unknown1a0; /* +0x1a0 */
    u8 unknown1a8[0x48];
    void *unknown1f0; /* +0x1f0 */
    u8 unknown1f8[0x38];
    void *unknown230; /* +0x230 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x40];
    Member057c9390_40 *unknown40; /* +0x40 */
};

extern Object057c9390 *D_57c9390;
extern const char D_15a8fba[5]; /* "Fall" */

/* derived names: a condition FUN_00640dc0 registers under "IsBoy_Fall" (lea
 * at 0x641817, its function stored at 0x5810e58): false without the record
 * or its object; true when the object's name is the one "Fall" looks up
 * (interned as a copy: `xor ecx, ecx`), else when its flag is clear and the
 * pointer at +0x230 is null or not the one at +0x1f0 */
// NONMATCHING: the last compare: the base branches to its own false block (`cmp rcx, [rbx+0x1f0];
// je`, then `mov bl, 1` shared with the other true edges), the build forms `setne` (181 bytes, base
// 178); written with early returns the two false arms merge into one block
bool FUN_00644c50() /* derived name */
{
    Member057c9390_40 *record = D_57c9390->unknown40;
    if (!record)
        return false;
    Member057c9390_40_1a0 *object = record->unknown1a0;
    if (!object)
        return false;
    return object->unknown68 == Name(D_15a8fba, false) ||
           (!object->unknown2441_1 &&
            !(record->unknown230 && record->unknown230 == record->unknown1f0));
}
