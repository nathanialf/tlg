/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores its pointer argument at +0x8 and its int at +0x9c;
 * slot 3 of 19 vtables, among them 0x16d5710 (stored by FUN_01078df0
 * FUN_013fac20 FUN_013fb820), 0x16d5760 (FUN_01078df0 FUN_013fb0e0
 * FUN_013fb5f0), 0x16d5a70 (FUN_010d9730 FUN_0140d390 FUN_0140dc00) and
 * 0x16d5ac0 (FUN_010d9730 FUN_0140d6a0 FUN_0140d9d0): a base class's own
 * method. The int is the store's width; the pointer's target is not traced.
 * Class and method unknown. */
struct Target014328e0; /* derived name */

struct Object014328e0 { /* derived name */
    u8 unknown0[0x8];
    Target014328e0 *unknown8;
    u8 unknown10[0x9c - 0x10];
    int unknown9c;
};

void FUN_014328e0(Object014328e0 *self, Target014328e0 *target, int value) /* derived name */
{
    self->unknown8 = target;
    self->unknown9c = value;
}
