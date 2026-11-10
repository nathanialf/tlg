/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores bit 0 of the int at +0x20c of the record the pointer
 * at +0x58 of its argument holds (a written & 1: the imm8 and) at +0x3c, 0
 * when the pointer is null; slot 14 of the vtable at 0x16ad098 (its pointer at
 * 0x16ad118). Class and method unknown. */
struct Record007790c0 { /* derived name */
    u8 unknown0[0x20c];
    int unknown20c;
};

struct Source007790c0 { /* derived name */
    u8 unknown0[0x58];
    Record007790c0 *unknown58;
};

struct Object007790c0 { /* derived name */
    u8 unknown0[0x3c];
    int unknown3c;
};

void FUN_007790c0(Object007790c0 *self, const Source007790c0 *source) /* derived name */
{
    Record007790c0 *record = source->unknown58;
    self->unknown3c = record ? record->unknown20c & 1 : 0;
}
