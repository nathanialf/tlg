/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 17 of the vtable at 0x16ae6a0 (its pointer at
 * 0x16ae738; stored by FUN_008181f0, FUN_00818360 and FUN_00818450): passes
 * each 8-byte entry of the array at +0x58 of its second argument (its count
 * at +0x60, both read once) by address to FUN_0138e360 with the member at
 * +0x58 of its third. Its first argument is unused; the types are not
 * traced. */
class Object00818ab0;  /* derived name */
struct Member00818ab0; /* derived name */

struct Entry00818ab0 { /* derived name */
    u8 unknown0[8];
};

struct Source00818ab0 { /* derived name */
    u8 unknown0[0x58];
    Entry00818ab0 *unknown58; /* +0x58 */
    u32 unknown60;            /* +0x60: the count of +0x58 */
};

struct Target00818ab0 { /* derived name */
    u8 unknown0[0x58];
    Member00818ab0 *unknown58; /* +0x58; not traced */
};

void FUN_0138e360(Member00818ab0 **member, Entry00818ab0 *entry); /* derived name */

void FUN_00818ab0(Object00818ab0 *, const Source00818ab0 *source,
                  Target00818ab0 *target) /* derived name */
{
    Entry00818ab0 *entry = source->unknown58;
    Entry00818ab0 *end = entry + source->unknown60;
    for (; entry != end; ++entry)
        FUN_0138e360(&target->unknown58, entry);
}
