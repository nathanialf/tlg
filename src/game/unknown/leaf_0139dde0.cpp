/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns a record through the hidden result pointer (rdi,
 * returned in rax) with its first 16 bytes zeroed (one 16-byte store); the
 * object (rsi) is unused; slot 13 of the vtable at 0x16d01a8 (its pointer at
 * 0x16d0220), the vtable stored by FUN_00b8c400 FUN_0139dbd0. The record's
 * size and fields are not traced: above 16 bytes, as the hidden pointer shows;
 * two 64-bit fields and 8 more bytes are written. Class and method unknown. */
struct Result0139dde0 { /* derived name */
    u64 unknown0;
    u64 unknown8;
    u8 unknown10[8]; /* the size is not traced */
};

struct Object0139dde0;

Result0139dde0 FUN_0139dde0(Object0139dde0 *self) /* derived name */
{
    Result0139dde0 result;
    result.unknown0 = 0;
    result.unknown8 = 0;
    return result;
}
