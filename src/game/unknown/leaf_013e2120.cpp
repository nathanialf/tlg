/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the float at 0xc48 of the record the pointer at 0x2a0
 * of the record the pointer at +0x8 holds points to; slot 8 of the vtable at
 * 0x16ca6b8 (its pointer at 0x16ca708); slot 8 of the vtable at 0x16d49a0 (its
 * pointer at 0x16d49f0). Class and method unknown. */
struct Record013e2120B { /* derived name */
    u8 unknown0[0xc48];
    float unknownc48;
};

struct Record013e2120A { /* derived name */
    u8 unknown0[0x2a0];
    Record013e2120B *unknown2a0;
};

struct Object013e2120 { /* derived name */
    u8 unknown0[8];
    Record013e2120A *unknown8;
};

float FUN_013e2120(Object013e2120 *self) /* derived name */
{
    return self->unknown8->unknown2a0->unknownc48;
}
