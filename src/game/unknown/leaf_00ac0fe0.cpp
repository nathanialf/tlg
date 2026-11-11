/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_types.h"

/* derived names: slot 5 of a soldier AI mode, slot 5 of the vtable at
 * 0x16b35a0 (stored by FUN_00abf490): calls FUN_00430580 on the object the
 * owner (+0x8) points at, then clears the byte at +0x18, copies that object's
 * int at +0x520 to +0x1c, clears the byte at +0x19 and sets the float at
 * +0x20 to minus infinity. The types are not traced beyond these fields.
 * Class and method unknown. */
struct Object00430580 { /* derived name */
    u8 unknown0[0x520];
    int unknown520; /* +0x520 */
};

struct Owner00ac0fe0 {        /* derived name */
    Object00430580 *unknown0; /* +0x0 */
};

struct Mode00ac0fe0 { /* derived name */
    u8 unknown0[0x8];
    Owner00ac0fe0 *unknown8; /* +0x8: the owner */
    u8 unknown10[0x8];
    bool unknown18; /* +0x18 */
    bool unknown19; /* +0x19 */
    u8 unknown1a[2];
    int unknown1c;   /* +0x1c */
    float unknown20; /* +0x20 */
};

void FUN_00430580(Object00430580 *object); /* derived name */

void FUN_00ac0fe0(Mode00ac0fe0 *self) /* derived name */
{
    FUN_00430580(self->unknown8->unknown0);
    self->unknown18 = false;
    self->unknown1c = self->unknown8->unknown0->unknown520;
    self->unknown19 = false;
    self->unknown20 = -HUGE_VALF;
}
