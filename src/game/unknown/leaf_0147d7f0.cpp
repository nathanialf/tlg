/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the float at 0xbb8 of the record the pointer at 0x280
 * of the record the pointer at +0x8 holds points to; slot 8 of the vtable at
 * 0x16caaf0 (its pointer at 0x16cab40); slot 8 of the vtable at 0x16d7390 (its
 * pointer at 0x16d73e0). Class and method unknown. */
struct Record0147d7f0B { /* derived name */
    u8 unknown0[0xbb8];
    float unknownbb8;
};

struct Record0147d7f0A { /* derived name */
    u8 unknown0[0x280];
    Record0147d7f0B *unknown280;
};

struct Object0147d7f0 { /* derived name */
    u8 unknown0[8];
    Record0147d7f0A *unknown8;
};

float FUN_0147d7f0(Object0147d7f0 *self) /* derived name */
{
    return self->unknown8->unknown280->unknownbb8;
}
