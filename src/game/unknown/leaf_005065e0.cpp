/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes the member at +0x8 of the object and the pointer its
 * second argument points to to FUN_005065f0, a tail call; slot 2 of the vtable
 * at 0x16aabe0 (its pointer at 0x16aac00), stored by FUN_00503fb0 and its
 * destructors FUN_00506910 and FUN_00506950. The member's type and the
 * callee's return type are not traced. */
struct Member005065e0_8 { /* derived name */
    u8 unknown0[8];
};

struct Object005065e0 { /* derived name */
    u8 unknown0[8];
    Member005065e0_8 unknown8;
};

void FUN_005065f0(Member005065e0_8 *member, void *value); /* derived name */

void FUN_005065e0(Object005065e0 *self, void *const *value) /* derived name */
{
    FUN_005065f0(&self->unknown8, *value);
}
