/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: when the pointer at +0x38 differs from the pointer at +0x160
 * of the record the pointer at +0x30 holds, passes the object to FUN_0131f630;
 * returns the pointer at +0x38 (reloaded after the call); slot 3 of the vtable
 * at 0x16d7ff8 (its pointer at 0x16d8020), stored by FUN_00b997d0,
 * FUN_00b9ced0, FUN_00bbc0d0, FUN_00bc28f0, FUN_00bc3da0 and FUN_00bd8040. The
 * pointers' types and the callee's return type are not traced. */
struct Record01499f70_30 { /* derived name */
    u8 unknown0[0x160];
    void *unknown160;
};

struct Object01499f70 { /* derived name */
    u8 unknown0[0x30];
    Record01499f70_30 *unknown30;
    void *unknown38;
};

void FUN_0131f630(Object01499f70 *object); /* derived name */

void *FUN_01499f70(Object01499f70 *self) /* derived name */
{
    if (self->unknown38 != self->unknown30->unknown160)
        FUN_0131f630(self);
    return self->unknown38;
}
