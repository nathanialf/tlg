/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns a record through the hidden result pointer (rdi,
 * returned in rax) with its first int 0; slot 4 of the vtable at 0x16a7e60
 * (its pointer at 0x16a7e90), no storing constructor listed; slot 4 of the
 * vtable at 0x16a8068 (its pointer at 0x16a8098), no storing constructor
 * listed; slot 4 of the vtable at 0x16aa9f8 (its pointer at 0x16aaa28), no
 * storing constructor listed; slot 4 of the vtable at 0x16aab38 (its pointer
 * at 0x16aab68), no storing constructor listed; and 70 more; FUN_005ccd60 also
 * passes its address (lea at 0x5f1b3e) to the function it tail-calls.
 * FUN_0057d330 and FUN_0057e840 have the same body. The record's size is not
 * traced (24 written, enough for the hidden pointer). Class and method
 * unknown. */
struct Result0057e840 { /* derived name */
    int unknown0;
    u8 unknown4[0x14]; /* the size is not traced */
};

struct Object0057e840; /* derived name */

Result0057e840 FUN_0057e840(Object0057e840 *self) /* derived name */
{
    Result0057e840 result;
    result.unknown0 = 0;
    return result;
}
