/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16b39a0 (a vtable slot; its vtable without
 * a row): through the pointer at +0x8 to the record whose first field points
 * to the owner, stores what FUN_00abfac0 returns for that record at +0x4 of
 * the owner's state at +0x380, or -1 when it equals the state's int at +0x0,
 * then points the owner's field at +0x430 to the object at 0x14f0820. Class
 * and method unknown; the types beyond their widths are not traced. */
struct State00acd950 { /* derived name */
    int unknown0;      /* +0x0 */
    int unknown4;      /* +0x4 */
};

struct Owner00acd950 { /* derived name */
    u8 unknown0[0x380];
    State00acd950 *unknown380; /* +0x380 */
    u8 unknown388[0xa8];
    const void *unknown430; /* +0x430; the object's type is not traced */
};

struct Handle00acd950 {   /* derived name */
    Owner00acd950 *owner; /* +0x0 */
};

struct Object00acd950 {       /* derived name */
    u8 unknown0[8];           /* +0x0: the vtable pointer */
    Handle00acd950 *unknown8; /* +0x8 */
};

extern const u8 D_14f0820[]; /* the type is not traced */

int FUN_00abfac0(Handle00acd950 *handle); /* derived name */

void FUN_00acd950(Object00acd950 *self) /* derived name */
{
    Owner00acd950 *owner = self->unknown8->owner;
    int value = FUN_00abfac0(self->unknown8);
    State00acd950 *state = owner->unknown380;
    state->unknown4 = state->unknown0 == value ? -1 : value;
    self->unknown8->owner->unknown430 = D_14f0820;
}
