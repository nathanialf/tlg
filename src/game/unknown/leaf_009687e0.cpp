/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 21 of the vtable at 0x16b1208 (stored by FUN_00961bf0
 * FUN_00967d40 FUN_00967e80): calls FUN_0092dbc0 on each of the object's
 * 0x100-byte entries (the array at +0x50, counted by the unsigned int at
 * +0x58, both read again after each call). The types are not traced. Class
 * and method unknown. */
struct Entry009687e0 { /* derived name */
    u8 unknown0[0x100];
};

struct Object009687e0 { /* derived name */
    u8 unknown0[0x50];
    Entry009687e0 *unknown50; /* +0x50 */
    u32 unknown58;            /* +0x58: the entry count */
};

void FUN_0092dbc0(Entry009687e0 *entry); /* derived name */

void FUN_009687e0(Object009687e0 *self) /* derived name */
{
    for (u32 i = 0; i < self->unknown58; i++)
        FUN_0092dbc0(&self->unknown50[i]);
}
