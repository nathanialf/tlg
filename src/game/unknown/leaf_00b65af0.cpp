/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: sets the int at +0x8 to -1; slot 0 of the vtable at 0x16b6ba0
 * (its pointer at 0x16b6bb0), no storing constructor listed, whose slots 1 and
 * 2 are an empty body and a 5-byte jump (the destructors' shape); the vtable
 * has no type info. Class and method unknown. */
struct Object00b65af0 { /* derived name */
    u8 unknown0[0x8];
    int unknown8;
};

void FUN_00b65af0(Object00b65af0 *self) /* derived name */
{
    self->unknown8 = -1;
}
