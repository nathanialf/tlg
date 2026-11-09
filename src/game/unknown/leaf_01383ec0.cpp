/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns a record through the hidden result pointer (rdi,
 * returned in rax) with the int 1 at +0x0 and the 16 bytes at +0x8 zeroed (one
 * 16-byte store); the object (rsi) is unused. The record's fields past the
 * first are not traced: two 64-bit fields are written; slot 13 of the vtable
 * at 0x16cd660 (its pointer at 0x16cd6d8), the vtable stored by FUN_009b3b10
 * FUN_01386900 FUN_013869c0; slot 6 of the vtable at 0x16cd6e0 (its pointer at
 * 0x16cd720), the vtable stored by FUN_009b3ef0. Class and method unknown. */
struct Result01383ec0 { /* derived name */
    int unknown0;
    u64 unknown8;
    u64 unknown10;
};

struct Object01383ec0; /* derived name */

Result01383ec0 FUN_01383ec0(const Object01383ec0 *) /* derived name */
{
    Result01383ec0 result;
    result.unknown0 = 1;
    result.unknown8 = 0;
    result.unknown10 = 0;
    return result;
}
