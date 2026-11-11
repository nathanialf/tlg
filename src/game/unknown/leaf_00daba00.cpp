/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 53 of the vtable at 0x16bb0c0 (its pointer at
 * 0x16bb278): clears the byte at +0xf58 and the int at +0xf60 of the record
 * at +0x7dc8. Class and method unknown. */
struct Record00daba00 { /* derived name */
    u8 unknown0[0xf58];
    u8 unknownf58;
    u8 unknownf59[0x7];
    int unknownf60;
};

struct Object00daba00 { /* derived name */
    u8 unknown0[0x7dc8];
    Record00daba00 *unknown7dc8;
};

void FUN_00daba00(Object00daba00 *self) /* derived name */
{
    self->unknown7dc8->unknownf58 = 0;
    self->unknown7dc8->unknownf60 = 0;
}
