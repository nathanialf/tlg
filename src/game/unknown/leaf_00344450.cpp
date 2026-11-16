/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_libc.h"

/* derived names: a virtual method (its address is a vtable's word, at
 * 0x16a87b0). The part at +0x240, when there is one, gets 16 less bit 1 of
 * its word at +0x100 at its +0x48; then, when the object at +0xc8 of the
 * object at +0x68 of the one the pointer at 0x57c9390 holds has a name at
 * +0xc0 that names a record this thread may use, and this object's flag at
 * +0x238 is set (bit 0), the sine of the holder's float at +0xd0 times 2.3 is taken
 * (0 without a holder). The classes are not traced. */
struct Part00344450 { /* derived name */
    u8 unknown0[0x48];
    int unknown48; /* +0x48 */
    u8 unknown4c[0xb4];
    u32 flags100; /* +0x100 */
};

struct Record00344450 { /* derived name */
    u8 unknown0[0x16];
    u16 flags16; /* +0x16 */
};

struct Named00344450 { /* derived name */
    u8 unknown0[0xc0];
    Name name; /* +0xc0 */
};

struct Holder00344450 { /* derived name */
    u8 unknown0[0xc8];
    Named00344450 *unknownc8; /* +0xc8 */
    float unknownd0;          /* +0xd0 */
};

struct Object057c9390 { /* derived name: the object, seen from here */
    u8 unknown0[0x68];
    Holder00344450 *unknown68; /* +0x68 */
};

extern Object057c9390 *D_57c9390;

struct Object00344450 { /* derived name */
    u8 unknown0[0x238];
    u8 flags238;        /* +0x238: bit 0 tested */
    Part00344450 *part; /* +0x240 */
};

void FUN_00344450(Object00344450 *self) /* derived name */
{
    if (Part00344450 *part = self->part)
        part->unknown48 = 16 - ((part->flags100 >> 1) & 1);
    Holder00344450 *holder = D_57c9390->unknown68;
    Named00344450 *named = holder->unknownc8;
    if (named && named->name.index != 0) {
        const Record00344450 *record =
            static_cast<const Record00344450 *>(D_17ac870[named->name.index].record18);
        if (record && ((record->flags16 & 4) || threadMayUse()) && (self->flags238 & 1)) {
            /* the sine's reader was a debug draw compiled out of the retail
             * build; the call to the C library stays */
            float sine = sin(holder ? holder->unknownd0 * 2.3f : 0.0f);
        }
    }
}
