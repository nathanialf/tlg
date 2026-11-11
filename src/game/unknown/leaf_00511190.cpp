/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores the pointers at 0x57dac00, 0x57dabf0 and 0x57dabf8
 * (the game's objects, read by many functions of the region, declared) at
 * +0x238, +0x240 and +0x248 of the object; slot 10 of the vtable at 0x16ab140
 * (its pointer at 0x16ab1a0), stored by FUN_00510fa0. The pointers' types are
 * not traced. */
extern void *D_57dac00;
extern void *D_57dabf0;
extern void *D_57dabf8;

struct Object00511190 { /* derived name */
    u8 unknown0[0x238];
    void *unknown238;
    void *unknown240;
    void *unknown248;
};

void FUN_00511190(Object00511190 *self) /* derived name */
{
    self->unknown238 = D_57dac00;
    self->unknown240 = D_57dabf0;
    self->unknown248 = D_57dabf8;
}
