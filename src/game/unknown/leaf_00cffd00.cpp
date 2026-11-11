/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 9 of the vtable at 0x16b9cb0 (its pointer at
 * 0x16b9d08): clears the u64 at +0x17c8 and the 0x810 bytes at +0xfb0 in a
 * loop (LoopIdiom makes it a memset call after TailCallElim has run, so the call
 * is not a tail call). Class and method unknown. */
struct Object00cffd00 { /* derived name */
    u8 unknown0[0xfb0];
    u32 unknownfb0[516];
    u8 unknown17c0[0x8];
    u64 unknown17c8;
};

void FUN_00cffd00(Object00cffd00 *self) /* derived name */
{
    self->unknown17c8 = 0;
    for (int i = 0; i < 516; ++i) {
        self->unknownfb0[i] = 0;
    }
}
