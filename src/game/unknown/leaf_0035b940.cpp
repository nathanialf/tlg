/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores the pointers at 0x57cf0d8, 0x57cf0c8 and 0x57cf0d0
 * (the game's objects, read by many functions of the region, declared) at
 * +0x238, +0x240 and +0x248 of the object; slot 10 of the vtable at 0x16a89f8
 * (its pointer at 0x16a8a58), stored by FUN_0035b770 and the destructors
 * FUN_0134de30 and FUN_0134de90. The pointers' types are not traced. */
extern void *D_57cf0d8;
extern void *D_57cf0c8;
extern void *D_57cf0d0;

struct Object0035b940 { /* derived name */
    u8 unknown0[0x238];
    void *unknown238;
    void *unknown240;
    void *unknown248;
};

void FUN_0035b940(Object0035b940 *self) /* derived name */
{
    self->unknown238 = D_57cf0d8;
    self->unknown240 = D_57cf0c8;
    self->unknown248 = D_57cf0d0;
}
