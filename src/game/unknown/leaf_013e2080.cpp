/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the float at 0xbd8 of the record the pointer at 0x2a0
 * of the record the pointer at +0x8 holds points to; slot 8 of the vtable at
 * 0x16ca660 (its pointer at 0x16ca6b0); slot 8 of the vtable at 0x16d4a50 (its
 * pointer at 0x16d4aa0). Class and method unknown. */
struct Record013e2080B { /* derived name */
    u8 unknown0[0xbd8];
    float unknownbd8;
};

struct Record013e2080A { /* derived name */
    u8 unknown0[0x2a0];
    Record013e2080B *unknown2a0;
};

struct Object013e2080 { /* derived name */
    u8 unknown0[8];
    Record013e2080A *unknown8;
};

float FUN_013e2080(Object013e2080 *self) /* derived name */
{
    return self->unknown8->unknown2a0->unknownbd8;
}
