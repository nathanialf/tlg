/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores at +0x458 of its second argument what FUN_00d84ba0
 * returns for the first field of the 32-byte entry of the table at 0x17ac870
 * the unsigned int at +0xc of that argument indexes; slot 2 of the vtable at
 * 0x16bacb0 (its pointer at 0x16bacd0; no constructor stores it), its slot 0
 * the empty method FUN_001af750. The object itself is not read; the entry's
 * field type is not traced. */
struct Object00d84b70; /* derived name */

struct Entry017ac870 { /* derived name */
    void *unknown0;
    u8 unknown8[0x18];
};

extern Entry017ac870 D_17ac870[];

struct Argument00d84b70 { /* derived name */
    u8 unknown0[0xc];
    unsigned unknownc;
    u8 unknown10[0x448];
    int unknown458;
};

int FUN_00d84ba0(void *value); /* derived name */

void FUN_00d84b70(Object00d84b70 *, Argument00d84b70 *argument) /* derived name */
{
    argument->unknown458 = FUN_00d84ba0(D_17ac870[argument->unknownc].unknown0);
}
