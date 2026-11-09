/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the int at +0xc is 19, as an int (sete, then
 * movzx to eax); slot 15 of the secondary vtable at 0x16abb60 (offset to top
 * -400) of the vtable at 0x16abb00 (its pointer at 0x16abbe8), stored by
 * FUN_005b05b0 FUN_005b14b0; slot 15 of the vtable at 0x16cb1a0 (its pointer
 * at 0x16cb228), the vtable stored by FUN_005b05b0 FUN_005b14b0. The function
 * is a base class's own method: the vtable 0x16cb1a0 holds it, and the
 * secondary vtable at 0x16abb60 (the base at +400 of the object whose vtable
 * is 0x16abb00) holds it unadjusted. Class and method unknown. */
struct Object0135e290 { /* derived name */
    u8 unknown0[0xc];
    int unknown0c; /* compared by FUN_0135e2a0, FUN_0135e2d0, FUN_0135e330 and FUN_0135e460 */
    u8 unknown10[0x14 - 0x10];
    int unknown14; /* compared by FUN_0135e290 */
};

// NONMATCHING: FUN_0135e460, the base returns the compare as `cmp; sete al; movzx eax, al`
// (11 bytes) and 4.0.0 as `xor eax, eax; cmp; sete al` (10 bytes): X86FixupSetCC
// (lib/Target/X86/X86FixupSetCC.cpp, new in LLVM 3.9) rewrites a setcc's zero
// extension into a zeroing xor before the flags. 3.8.1 emits the base's shape from
// this source, 3.9.1 and 4.0.0-src the other. The base's game region has 1,548
// setcc+movzx pairs in 775 functions and no matched game row holds one.
int FUN_0135e460(const Object0135e290 *self) /* derived name */
{
    return self->unknown0c == 19;
}
