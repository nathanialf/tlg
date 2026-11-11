/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_math.h"

/* derived names: slot 2 of the vtables at 0x16bfc28 and 0x16bfcb8: calls FUN_013d9150
 * on the object, then sets the int at 0x70 to 0. Class and method unknown.
 * FUN_013d90d0 (its address at 0x16bfc90) calls FUN_013d9150 too, then resets
 * the members at +0x80 and +0xa0 through FUN_013d8be0, each followed by an int
 * (+0x70, +0x74) set to 0 and an aligned vector (+0xd0, +0xe0) zeroed. The
 * members' type is not traced. */
struct Member013d9130 { /* derived name */
    u8 unknown0[0x20];
};

struct Object013d9130 { /* derived name */
    u8 unknown0[0x70];
    int unknown70;
    int unknown74;
    u8 unknown78[8];
    Member013d9130 unknown80;
    Member013d9130 unknowna0;
    u8 unknownc0[0x10];
    Float4A unknownd0;
    Float4A unknowne0;
};

void FUN_013d9150(Object013d9130 *self);   /* derived name */
void FUN_013d8be0(Member013d9130 *member); /* derived name */

void FUN_013d9130(Object013d9130 *self) /* derived name */
{
    FUN_013d9150(self);
    self->unknown70 = 0;
}

void FUN_013d90d0(Object013d9130 *self) /* derived name */
{
    FUN_013d9150(self);
    FUN_013d8be0(&self->unknown80);
    self->unknown70 = 0;
    self->unknownd0.set(0.0f, 0.0f, 0.0f, 0.0f);
    FUN_013d8be0(&self->unknowna0);
    self->unknown74 = 0;
    self->unknowne0.set(0.0f, 0.0f, 0.0f, 0.0f);
}
