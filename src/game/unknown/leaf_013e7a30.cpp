/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores its pointer at +0x8 and its third and fourth ints at
 * +0x9c and +0xa0, then calls FUN_013e5560 with the object and its second int
 * as a tail call; slot 3 of the vtable at 0x16d4ba0 (its pointer at
 * 0x16d4bc8); slot 3 of the vtable at 0x16d4d50 (its pointer at 0x16d4d78).
 * Class and method unknown. */
struct Object013e7a30 { /* derived name */
    u8 unknown0[8];
    void *unknown8;
    u8 unknown10[0x8c];
    int unknown9c;
    int unknowna0;
};

void FUN_013e5560(Object013e7a30 *self, int value); /* derived name */

void FUN_013e7a30(Object013e7a30 *self, void *pointer, int value, int a, int b) /* derived name */
{
    self->unknown8 = pointer;
    self->unknown9c = a;
    self->unknowna0 = b;
    FUN_013e5560(self, value);
}
