/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the 64-bit value at +0x0 of the 32-byte entry of the
 * table at 0x17ac870 the unsigned int at +0x34 indexes (zero-extended:
 * unsigned). The table is the game's object (config/modules.base.txt), read
 * directly from many functions of the region (0x1b05af, 0x1b0780 and on), so
 * it is declared here and the game module's stand-in defines it; the base
 * indexes with the table as the index (`mov rax, [rax + rcx]`), which a
 * table the module defines compiles to. Its entries' other fields and the
 * value's type are not traced; slot 5 of the vtable at 0x16b01f0 (its
 * pointer at 0x16b0228), the vtable stored by FUN_008c1650 FUN_008c17c0.
 * Class and method unknown. */
struct Entry017ac870 { /* derived name */
    u64 unknown0;
    u8 unknown8[0x18];
};

extern const Entry017ac870 D_17ac870[];

struct Object01373a50 { /* derived name */
    u8 unknown0[0x34];
    unsigned unknown34;
};

u64 FUN_01373a50(const Object01373a50 *self) /* derived name */
{
    return D_17ac870[self->unknown34].unknown0;
}
