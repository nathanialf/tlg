/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears bit 1 of the byte at +0x16, passes the object the
 * pointer at 0x5945a38 holds and the object to FUN_00cbc0d0, then calls the
 * third function of the table the pointer at +0x18 holds with the object, a
 * tail call; slot 2 of the vtable at 0x16a76f8 (its pointer at 0x16a7718),
 * stored by FUN_00204080, FUN_007609e0 and the destructor of Object00204320.
 * The table's other entries and the callees' return types are not traced. */
struct Object00cb66f0; /* derived name */
struct Object05945a38; /* derived name */

struct Functions00cb66f0 { /* derived name */
    void (*unknown0)(Object00cb66f0 *object);
    void (*unknown8)(Object00cb66f0 *object);
    void (*unknown10)(Object00cb66f0 *object);
};

struct Object00cb66f0 { /* derived name */
    u8 unknown0[0x16];
    bool unknown16_0 : 1;
    bool unknown16_1 : 1;
    u8 unknown17;
    const Functions00cb66f0 *unknown18;
};

extern Object05945a38 *D_5945a38;

void FUN_00cbc0d0(Object05945a38 *object, Object00cb66f0 *item); /* derived name */

void FUN_00cb66f0(Object00cb66f0 *self) /* derived name */
{
    self->unknown16_1 = false;
    FUN_00cbc0d0(D_5945a38, self);
    self->unknown18->unknown10(self);
}
