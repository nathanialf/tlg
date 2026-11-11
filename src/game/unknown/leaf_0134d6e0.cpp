/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the 64-bit value at +0x0 of the 32-byte entry of the
 * table at 0x17ac870 the unsigned int at +0x288 indexes, as FUN_01373a50
 * (leaf_01373a50.cpp) does with +0x34: the table is the game's object,
 * declared here and defined by the game module's stand-in. Slot 12 of seven
 * vtables (0x16a8830, 0x16a89f8, 0x16aaf60, 0x16ab140, 0x16ac180, 0x16c7608,
 * 0x16cb520) and slot 1 of 0x16c79a0. The value's type is not traced. */
struct Entry017ac870 { /* derived name */
    u64 unknown0;
    u8 unknown8[0x18];
};

extern const Entry017ac870 D_17ac870[];

struct Object0134d6e0 { /* derived name */
    u8 unknown0[0x288];
    unsigned unknown288;
};

u64 FUN_0134d6e0(const Object0134d6e0 *self) /* derived name */
{
    return D_17ac870[self->unknown288].unknown0;
}
