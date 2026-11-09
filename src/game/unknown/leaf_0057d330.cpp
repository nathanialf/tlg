/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns a record through the hidden result pointer (rdi,
 * returned in rax) with its first int 0; slot 4 of the vtable at 0x16ab710
 * (its pointer at 0x16ab740), no storing constructor listed. FUN_0057d330 and
 * FUN_0057e840 have the same body. The record's size is not traced (24
 * written, enough for the hidden pointer). Class and method unknown. */
struct Result0057e840 { /* derived name */
    int unknown0;
    u8 unknown4[0x14]; /* the size is not traced */
};

struct Object0057d330; /* derived name */

Result0057e840 FUN_0057d330(Object0057d330 *self) /* derived name */
{
    Result0057e840 result;
    result.unknown0 = 0;
    return result;
}
