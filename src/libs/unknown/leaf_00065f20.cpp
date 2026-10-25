/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: an object holding a pointer at +0 and twelve 32-byte
 * records from +0x10 (an array and an int each; FUN_00065f00 returns one by
 * index). Its constructor FUN_00065b70 sets the flag at +0x198; this
 * function clears it (called at 0x6dd1f and 0x14e946, after the records
 * are filled). */
struct Object00065f20 /* derived name */
{
    u8 unknown0[0x198];
    bool open; /* derived name */
};

void FUN_00065f20(Object00065f20 *self) /* derived name */
{
    self->open = false;
}
