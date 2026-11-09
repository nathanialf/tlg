/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns a record through the hidden result pointer (rdi,
 * returned in rax) with its first byte, a bool, false; slot 9 of the vtable at
 * 0x16b6dc8 (its pointer at 0x16b6e20), the vtable stored by FUN_00b7dea0
 * FUN_00b7f5f0 FUN_00b7f710 FUN_00b806b0 FUN_00b81790 FUN_00b82290. Slot 8
 * (FUN_00b7fee0) returns through the hidden pointer as well. The record's size
 * is not traced: above 16 bytes, as the hidden pointer shows; 24 is written.
 * Class and method unknown. */
struct Result0139d9e0 { /* derived name */
    bool valid;
    u8 unknown1[0x17]; /* the size is not traced */
};

struct Object0139d9e0;

Result0139d9e0 FUN_0139d9e0(Object0139d9e0 *self) /* derived name */
{
    Result0139d9e0 result;
    result.valid = false;
    return result;
}
