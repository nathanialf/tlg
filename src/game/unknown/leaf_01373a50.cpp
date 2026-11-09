/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the 64-bit value at +0x0 of the 32-byte entry of the
 * table at 0x17ac870 the unsigned int at +0x34 indexes (zero-extended:
 * unsigned). The table is an extern stand-in (its lea is the relaxed GOT load
 * an extern compiles to, D10); its entries' other fields and the value's type
 * are not traced; slot 5 of the vtable at 0x16b01f0 (its pointer at
 * 0x16b0228), the vtable stored by FUN_008c1650 FUN_008c17c0. Class and method
 * unknown. */
struct Entry017ac870 { /* derived name */
    u64 unknown0;
    u8 unknown8[0x18];
};

extern const Entry017ac870 D_17ac870[];

struct Object01373a50 { /* derived name */
    u8 unknown0[0x34];
    unsigned unknown34;
};

// NONMATCHING: the address's operand order, the region's open linkage question (NOTES, round 110A ruling): the base indexes with the table as the index (`mov rax, [rax + rcx]`), as a static definition compiles (tested); this extern stand-in's relaxed GOT lea makes the table the base (`[rcx + rax]`). The table is read directly from many functions of the region (0x1b05af, 0x1b0780 and on), so it is not one file's object
u64 FUN_01373a50(const Object01373a50 *self) /* derived name */
{
    return D_17ac870[self->unknown34].unknown0;
}
