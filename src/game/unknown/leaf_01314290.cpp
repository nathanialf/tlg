/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_drawcontext.h"

/* derived names: an index buffer as the draw context reads it: its address
 * in two words, the high one's low 12 bits kept, and its index count */
struct IndexBuffer01314290 {
    u8 unknown0[0x60];
    u32 addressLow;  /* +0x60 */
    u32 addressHigh; /* +0x64 */
    u32 count;       /* +0x68 */
};

/* derived name: the index buffer for the next draws (null: none), its
 * address and its count each written only when it changed */
void FUN_01314290(DrawContext01314290 *self, const IndexBuffer01314290 *buffer)
{
    u64 address = 0;
    u32 count = 0;
    if (buffer) {
        address = (static_cast<u64>(buffer->addressHigh) & 0xfff) << 32 | buffer->addressLow;
        count = buffer->count;
    }
    if (self->unknown278 == 0x200)
        return;
    if (address != self->indexAddress) {
        self->indexAddress = address;
        self->setIndexBuffer(address);
    }
    if (count != self->indexCount) {
        self->indexCount = count;
        self->setIndexCount(count);
    }
}
