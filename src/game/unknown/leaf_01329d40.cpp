/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_commandbuffer.h"
#include "tlg_game_gnm.h"

/* derived name: sets a render target in a slot through FUN_012fb8d0, from a
 * copy of it: a target that clears fast (bit 13 of the color info) without
 * compression (bit 14), with no fmask but a cmask, gets its fmask from its
 * color surface (the tile mode, the slice and pitch counts and the base
 * address), compression off; no target clears the slot */
// NONMATCHING: the base tests the compression bit and the fast clear bit in two branches where this build joins them in one mask test (`and 0x6000; cmp 0x2000`), and reads the copy's color info and attributes again after the call to FUN_001a44c0 where the link here keeps them (its callees FUN_012fc0a0, FUN_012fc330 and FUN_012fb8d0 inferred nocapture, the copy not escaping); the rest, the inlined null target's packet included, is the base's (70/154)
void FUN_01329d40(CommandBuffer01496a80 *buffer, u32 slot, const RenderTarget0149a070 *target)
{
    if (!target) {
        FUN_012fb8d0(buffer, slot, 0);
        return;
    }
    RenderTarget0149a070 copy = *target;
    if (!(copy.colorInfo & 0x4000) && (copy.colorInfo & 0x2000)) {
        if (copy.fmaskAddress() == 0 && copy.cmaskAddress != 0) {
            copy.colorInfo &= ~0x4000u;
            copy.attributes = (copy.attributes & ~0x3e0u) | (copy.attributes & 0x1f) << 5;
            copy.fmaskSlice = (copy.fmaskSlice & 0xffc00000) | (copy.slice & 0x3fffff);
            copy.pitch = (copy.pitch & 0x800fffff) | (copy.pitch & 0x7ff) << 20;
            FUN_012fc330(&copy, FUN_012fc0a0(&copy));
        }
    }
    FUN_012fb8d0(buffer, slot, &copy);
}
