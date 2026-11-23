/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: four bytes of a value in the other order, in the type of
 * the value given, and a 64-bit value swapped as its two halves: the low
 * half as a u32 (a 32-bit `bswap` in the base), the high half as the
 * shifted 64-bit value (shifts and masks in the base) */
#define SWAP32(v)                                                                                  \
    ((((v) >> 24) & 0xff) | (((v) >> 8) & 0xff00) | (((v) << 8) & 0xff0000) |                      \
     (((v) << 24) & 0xff000000))

static inline u8 swapBytes(u8 v) /* derived name */
{
    return v;
}

static inline u64 swapBytes(u64 v) /* derived name */
{
    return SWAP32(v >> 32) | (u64(SWAP32(u32(v))) << 32);
}

/* derived names: an output buffer of 0x3fe00 bytes: its bytes at +0xc10,
 * the count written at +0xc20 and at +0xc28 a flag set once a write would
 * pass the end (each write still made); values are written big-endian,
 * their bytes swapped after the test */
struct Buffer00dcaee0 { /* derived name */
    u8 unknown0[0xc10];
    u8 *data; /* +0xc10 */
    u8 unknownc18[0x8];
    u64 size; /* +0xc20 */
    int full; /* +0xc28 */

    template <class T> void write(T value) /* derived name */
    {
        if (size + sizeof(T) > 0x3fe00)
            full = 1;
        *reinterpret_cast<T *>(data + size) = swapBytes(value);
        size += sizeof(T);
    }
};

/* derived name: the writer, its buffer at +0x28 */
struct Writer00dcaee0 { /* derived name */
    u8 unknown0[0x28];
    Buffer00dcaee0 *buffer; /* +0x28 */
};

void FUN_013bcc20(Writer00dcaee0 *writer, int tag);     /* derived name */
void FUN_00dca5c0(Writer00dcaee0 *writer, int unknown); /* derived name */

/* derived names: a record of tag 9: FUN_013bcc20 starts it, then a byte and
 * two 64-bit values (big-endian); a buffer that came out full
 * is handed to FUN_00dca5c0 */
// NONMATCHING: 6/98 (365 bytes, base 382): the swaps' operations are the base's (a 32-bit
// `bswap` of the low half, shifts and masks of the high half, the ors in the base's tree,
// each swap after its test), the schedule not: the base copies the value four times, then
// shifts, masks and ors each as a group (0xff000000 held in r8d for both swaps); the low
// half's operand first in the source gave 58/98 with the copies in the base's other order
void FUN_00dcaee0(Writer00dcaee0 *writer, u64 first, u8 kind, u64 second) /* derived name */
{
    FUN_013bcc20(writer, 9);
    writer->buffer->write(kind);
    writer->buffer->write(first);
    writer->buffer->write(second);
    if (writer->buffer->full)
        FUN_00dca5c0(writer, 0);
}
