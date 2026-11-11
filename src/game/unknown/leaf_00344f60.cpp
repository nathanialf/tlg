/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores the pointers at 0x57ce900, 0x57ce8f0 and 0x57ce8f8
 * (the game's objects, read by many functions of the region, declared) at
 * +0x238, +0x240 and +0x248 of the object; slot 10 of the vtable at 0x16a8830
 * (its pointer at 0x16a8890), stored by FUN_00344a60 and the destructors
 * FUN_0134d520 and FUN_0134d600. The pointers' types are not traced. */
extern void *D_57ce900;
extern void *D_57ce8f0;
extern void *D_57ce8f8;

struct Object00344f60 { /* derived name */
    u8 unknown0[0x238];
    void *unknown238;
    void *unknown240;
    void *unknown248;
};

void FUN_00344f60(Object00344f60 *self) /* derived name */
{
    self->unknown238 = D_57ce900;
    self->unknown240 = D_57ce8f0;
    self->unknown248 = D_57ce8f8;
}
