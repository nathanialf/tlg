/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores the pointers at 0x57da758, 0x57da748 and 0x57da750
 * (the game's objects, read by many functions of the region, declared) at
 * +0x238, +0x240 and +0x248 of the object; slot 10 of the vtable at 0x16aaf60
 * (its pointer at 0x16aafc0), stored by FUN_00510130. The pointers' types are
 * not traced. */
extern void *D_57da758;
extern void *D_57da748;
extern void *D_57da750;

struct Object00510330 { /* derived name */
    u8 unknown0[0x238];
    void *unknown238;
    void *unknown240;
    void *unknown248;
};

void FUN_00510330(Object00510330 *self) /* derived name */
{
    self->unknown238 = D_57da758;
    self->unknown240 = D_57da748;
    self->unknown248 = D_57da750;
}
