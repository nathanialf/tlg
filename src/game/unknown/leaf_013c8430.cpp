/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the int at +4 of the record at +0x58 of the object at
 * +0x20; slot 4 of the vtable at 0x16bc108 (its pointer at 0x16bc138), the
 * vtable stored by FUN_00db4100. FUN_013c8430, FUN_013c84a0 and FUN_013c84b0
 * are slots 4, 6 and 8 of the same vtable. Class and method unknown. */
struct Record013c8430 { /* derived name */
    u8 unknown0[4];
    int unknown4; /* returned by FUN_013c8430 */
    int unknown8; /* returned by FUN_013c84a0 */
    u8 unknownc[0x10 - 0xc];
    u8 unknown10[4]; /* its address returned by FUN_013c84b0; type and size not traced */
};

struct Target013c8430 { /* derived name */
    u8 unknown0[0x58];
    Record013c8430 *unknown58;
};

struct Object013c8430 { /* derived name */
    u8 unknown0[0x20];
    Target013c8430 *unknown20;
};

int FUN_013c8430(const Object013c8430 *self) /* derived name */
{
    return self->unknown20->unknown58->unknown4;
}
