/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores 8 in the ints at +0x2c and +0x30 (one 64-bit store),
 * then calls FUN_001ab470 on the object as a tail call; no caller or pointer
 * slot found. The callee's return type is not traced. Class and method
 * unknown. */
struct Object001ab450 { /* derived name */
    u8 unknown0[0x2c];
    int unknown2c;
    int unknown30;
};

void FUN_001ab470(Object001ab450 *self); /* derived name */

void FUN_001ab450(Object001ab450 *self) /* derived name */
{
    self->unknown2c = 8;
    self->unknown30 = 8;
    FUN_001ab470(self);
}
