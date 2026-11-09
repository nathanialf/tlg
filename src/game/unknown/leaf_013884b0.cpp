/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the int at +0x4 of the 8-byte entry its index selects
 * in the array at +0x14 (the index a 32-bit unsigned value, zero-extended);
 * slot 3, FUN_013884a0, returns the entry's address. slot 4 of the vtable at
 * 0x16b9a90 (its pointer at 0x16b9ac0), the vtable stored by FUN_00cf5710;
 * slot 4 of the vtable at 0x16c7208 (its pointer at 0x16c7238), the vtable
 * stored by FUN_0021c020 FUN_01346b90 FUN_01346c10 FUN_01346cc0; slot 4 of the
 * vtable at 0x16c72e0 (its pointer at 0x16c7310), the vtable stored by
 * FUN_001bd010 FUN_002370b0 FUN_002efa10 FUN_00326c10 FUN_0033b550
 * FUN_00490100 FUN_0050cb90 FUN_00537dd0 FUN_005ccd60 FUN_006233e0
 * FUN_00657410 FUN_006e1f00 FUN_007b3320 FUN_007dfc40 FUN_00840f90
 * FUN_0085eb50 FUN_008c25c0 FUN_0091bb60 FUN_0092ddb0 FUN_00953d00
 * FUN_0096ac80 FUN_00991fe0 FUN_0099cbc0 FUN_009b6a60 FUN_009c42e0
 * FUN_009f5f50 FUN_00ad9d20 FUN_00af1a70 FUN_00b389c0 FUN_00bdd2f0
 * FUN_00bf1e30 FUN_00bf5f90 FUN_00c15920 FUN_00c7aee0 FUN_00c93c40
 * FUN_00cf2ea0 FUN_00d00e40 FUN_00d5d260 FUN_00e01d40 FUN_00e03660
 * FUN_00e10cd0 FUN_0134a310 FUN_0134a6f0; slot 4 of the vtable at 0x16c73a8
 * (its pointer at 0x16c73d8), the vtable stored by FUN_001bd010 FUN_002370b0
 * FUN_002aa7b0 FUN_00537dd0 FUN_005ccd60 FUN_005fb1d0 FUN_0069d690
 * FUN_0077c7f0 FUN_007b3320 FUN_00830fb0 FUN_00840f90 FUN_00909420
 * FUN_0091bb60 FUN_00925b30 FUN_0092ddb0 FUN_00953d00 FUN_00a2b8c0
 * FUN_00a31aa0 FUN_00ad9d20 FUN_00b774e0 FUN_00bf0510 FUN_00bf1e30
 * FUN_00bf5f90 FUN_00c15920 FUN_00c7aee0 FUN_00ca4420 FUN_00cd0750
 * FUN_00d15970 FUN_00d1ffc0 FUN_00d57330 FUN_00dfe9a0 FUN_00e03660
 * FUN_00e10cd0 FUN_00e82e80 FUN_011004c0 FUN_0134ae30; and 21 more. The count
 * of entries is not traced. Class and method unknown. */
struct Entry013884b0 { /* derived name */
    int unknown0;
    int unknown4;
};

struct Object013884b0 { /* derived name */
    u8 unknown0[0x14];
    Entry013884b0 entries[1]; /* the count is not traced */
};

int FUN_013884b0(const Object013884b0 *self, u32 index) /* derived name */
{
    return self->entries[index].unknown4;
}
