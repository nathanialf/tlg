/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_gnm.h"

/* derived names: a depth target kept in step with the depth surface it
 * draws to (called by FUN_013143e0): when the surface's count at +0x160
 * differs from the one last seen, its address at +0x30 becomes the target's
 * depth read and write address and its byte at +0x148 flag 29 of the
 * target's first word, and the count is kept. The other fields are not
 * traced. */
struct DepthSurface01496af0 { /* derived name */
    u8 unknown0[0x30];
    void *address; /* +0x30 */
    u8 unknown38[0x110];
    bool unknown148; /* +0x148 */
    u8 unknown149[0x17];
    u64 count; /* +0x160 */
};

struct DepthTarget01496af0 { /* derived name */
    void update();

    u8 unknown0[0x30];
    DepthSurface01496af0 *surface; /* +0x30 */
    u64 count;                     /* +0x38: the surface's count last seen */
    u8 unknown40[0x18];
    DepthRenderTarget01499280 target; /* +0x58 */
};

// NONMATCHING: register assignment only: the surface pointer takes rcx and the count rax in the base, the reverse here (three source forms measured: ==, its operands swapped, the early return as a block)
// Round 507D: the surface is a global range (used after the test) and takes rax before the local
// count; in the base the count takes rax first.
// Round 552C, module dump: the surface is global (used in the next block) and queued before the
// local count, so it takes rax; the base gives the count rax.
void DepthTarget01496af0::update() /* derived name */
{
    if (count != surface->count) {
        target.setZReadAddress(surface->address);
        target.setZWriteAddress(surface->address);
        target.setFlag29(surface->unknown148);
        count = surface->count;
    }
}
