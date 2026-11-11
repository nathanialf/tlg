/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback whose address the function at 0x21bad3 stores
 * with the number 2 in an entry of a growing array of 24-byte entries (0x1345f70
 * beside it, with 15): when the record its third argument points to first has
 * a nonzero int at +0x8, keeps that record and the pointer that follows it in
 * the two objects at 0x57ca418 and 0x57ca420, which only this function and
 * FUN_01345f70 reach (this file's). The first two arguments are not read; the
 * types are not traced. */
struct Value01345f20 { /* derived name */
    u8 unknown0[0x8];
    int unknown8;
};

struct Arguments01345f20 { /* derived name */
    Value01345f20 *unknown0;
    void *unknown8;
};

static Value01345f20 *D_57ca418;
static void *D_57ca420;

void FUN_01345f20(void *, void *, const Arguments01345f20 *arguments) /* derived name */
{
    if (arguments->unknown0->unknown8 != 0) {
        D_57ca418 = arguments->unknown0;
        D_57ca420 = arguments->unknown8;
    }
}
