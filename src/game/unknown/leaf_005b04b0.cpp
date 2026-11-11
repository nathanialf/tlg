/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 11 of the vtable at 0x16abb60 (its pointer at
 * 0x16abbc8), stored by FUN_005b05b0 and FUN_005b14b0: whether, on the object
 * the pointer at +0x40 of the object the pointer at 0x57c9390 holds, the
 * record its pointer at +0x1a0 holds has bit 3 of the byte at +0x2421 set and
 * a pointer at +0x21c0 to a record whose int at +0x2c is 2 (false where any
 * pointer is null). The object itself is not read. Class and method
 * unknown. */
struct Member005b04b0_21c0 /* derived name */
{
    u8 unknown0[0x2c];
    int unknown2c; /* +0x2c */
};

struct Member005b04b0_1a0 /* derived name */
{
    u8 unknown0[0x21c0];
    Member005b04b0_21c0 *unknown21c0; /* +0x21c0 */
    u8 unknown21c8[0x259];
    u8 unknown2421; /* +0x2421 */
};

struct Member057c9390_40 /* derived name */
{
    u8 unknown0[0x1a0];
    Member005b04b0_1a0 *unknown1a0; /* +0x1a0 */
};

struct Object057c9390 /* derived name */
{
    u8 unknown0[0x40];
    Member057c9390_40 *unknown40; /* +0x40 */
};

extern Object057c9390 *D_57c9390;

struct Object005b04b0; /* derived name */

static int isReady(const Member057c9390_40 *owner) /* derived name */
{
    const Member005b04b0_1a0 *record = owner->unknown1a0;
    if (!record || !(record->unknown2421 & 8))
        return 0;
    const Member005b04b0_21c0 *member = record->unknown21c0;
    if (member && member->unknown2c == 2)
        return 1;
    return 0;
}

// NONMATCHING: the default's placement, as leaf_00670990.cpp's: this keeps the 0 in
// eax for every failed test (the record in rcx), where the base loads the record
// into rax and sets the 0 again in one block the inner tests reach (`xor eax,
// eax` before the `ret`).
int FUN_005b04b0(const Object005b04b0 *) /* derived name */
{
    int ready = 0;
    const Member057c9390_40 *owner = D_57c9390->unknown40;
    if (owner)
        ready = isReady(owner);
    return ready;
}
