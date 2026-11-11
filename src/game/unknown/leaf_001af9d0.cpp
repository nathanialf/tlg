/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the first 16-byte entry of the array at +0x58 whose
 * byte at +0x3 is the key, of as many as the byte at +0x28 counts, or null;
 * called twice by FUN_0131e850. The entries' other fields are not traced.
 * Class and method unknown. */
struct Entry001af9d0 /* derived name */
{
    u8 unknown0[3];
    u8 unknown3; /* +0x3: the key */
    u8 unknown4[0xc];
};

struct Object001af9d0 /* derived name */
{
    u8 unknown0[0x28];
    u8 unknown28; /* +0x28: the count */
    u8 unknown29[0x2f];
    Entry001af9d0 *unknown58; /* +0x58 */
};

// NONMATCHING: LoopStrengthReduce's choice: the base walks a pointer to the key byte
// (+0x3) and rebuilds the entry from the index at the exit (`shl rsi, 4; add r8,
// rsi`), where this walks one pointer to the entry and returns it.
Entry001af9d0 *FUN_001af9d0(const Object001af9d0 *self, u8 key) /* derived name */
{
    for (int i = 0; i < self->unknown28; i++)
        if (self->unknown58[i].unknown3 == key)
            return &self->unknown58[i];
    return 0;
}
