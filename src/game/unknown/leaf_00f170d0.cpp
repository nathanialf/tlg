/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a read callback FUN_00f16b10 stores (lea at 0xf16cf1): for the
 * data at the unsigned offset from the pointer at +0x0 of the source, hands
 * back the data's own address through the out pointer when there is one and
 * the address is 4-byte aligned; otherwise copies the given size into the
 * buffer through FUN_00ed1a40 and hands back the buffer when there is an out
 * pointer. Returns 0. The callback's signature is taken from its body. */
struct Source00f170d0 /* derived name */
{
    const u8 *unknown0; /* +0x0: the data */
};

void FUN_00ed1a40(void *buffer, const void *data, u64 size); /* derived name */

int FUN_00f170d0(const Source00f170d0 *self, unsigned offset, void *buffer, u64 size,
                 const void **out) /* derived name */
{
    const u8 *data = self->unknown0 + offset;
    if ((reinterpret_cast<u64>(data) & 3) == 0 && out) {
        *out = data;
    } else {
        FUN_00ed1a40(buffer, data, size);
        if (out)
            *out = buffer;
    }
    return 0;
}
